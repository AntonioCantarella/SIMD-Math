#pragma once

#include <type_traits>
#include "Windows.h"
#include <iostream>
#include "ITestable.h"

template<class T, typename = std::enable_if_t<std::is_base_of_v<ITestable, T>>>
class Performance
{
public:
	static void Test(const int _count)
	{
		LARGE_INTEGER starting_time, ending_time, elapsed_microseconds;
		LARGE_INTEGER frequency;

		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&starting_time);

		long long max_time = 0;
		long long min_time = 100'000'000;
		long long total_time = 0;

		long long max_ticks = 0;
		long long min_ticks = 100'000'000;
		long long total_ticks = 0;

		long long current_ticks = 0;
		long long current_time = 0;

		float percent = 0.f;

		unsigned long long start_cpu_cycles = 0;
		QueryProcessCycleTime(GetCurrentProcess(), &start_cpu_cycles);

		__pragma(loop(no_vector))
		for (int i = 0; i < _count; ++i)
		{
			TestOnce(current_time, current_ticks);

			if(100.f / _count * i > percent)
			{
				std::cout << "|" << percent << "|";
				percent += 10.f;
			}

			if(current_time > max_time)
				max_time = current_time;
			if(current_time < min_time)
				min_time = current_time;
			total_time += current_time;

			if(current_ticks > max_ticks)
				max_ticks = current_ticks;
			if(current_ticks < min_ticks)
				min_ticks = current_ticks;
			total_ticks += current_ticks;
		}

		unsigned long long stop_cpu_cycles = 0;
		QueryProcessCycleTime(GetCurrentProcess(), &stop_cpu_cycles);

		const unsigned long long delta_cpu_cycles = stop_cpu_cycles - start_cpu_cycles;

		QueryPerformanceCounter(&ending_time);
		elapsed_microseconds.QuadPart = ending_time.QuadPart - starting_time.QuadPart;
		const long long total_ticks_brut = elapsed_microseconds.QuadPart;
		elapsed_microseconds.QuadPart *= 1'000'000;
		elapsed_microseconds.QuadPart /= frequency.QuadPart;

		std::cout << std::endl;
		std::cout << "----- Function executed " << _count << " times -----" << std::endl;
		std::cout << "T - Max : " << max_time << " us" << std::endl;
		std::cout << "I - Min : " << min_time << " us" << std::endl;
		std::cout << "M - Total (Sum) : " << total_time << " us" << std::endl;
		std::cout << "E - Total (Query) : " << elapsed_microseconds.QuadPart << " us" << std::endl;
		std::cout << "S - Average : " << total_time / _count << " us" << std::endl;
		std::cout << "--------------------------------" << std::endl;
		std::cout << "T - Max : " << max_ticks << " ticks" << std::endl;
		std::cout << "I - Min : " << min_ticks << " ticks" << std::endl;
		std::cout << "C - Total (Sum) : " << total_ticks << " ticks" << std::endl;
		std::cout << "K - Total (Query) : " << total_ticks_brut << " ticks" << std::endl;
		std::cout << "S - Average : " << total_ticks / _count << " ticks" << std::endl;
		std::cout << " --> CPU Cycles = " << delta_cpu_cycles << " cycles" << std::endl;
	}

private:
	static void TestOnce(long long& _time, long long& _ticks)
	{
		T test;
		test.Prepare();

		LARGE_INTEGER starting_time, ending_time, elapsed_microseconds;
		LARGE_INTEGER frequency;

		QueryPerformanceFrequency(&frequency);
		QueryPerformanceCounter(&starting_time);

		test.Execute();

		QueryPerformanceCounter(&ending_time);

		elapsed_microseconds.QuadPart = ending_time.QuadPart - starting_time.QuadPart;
		_ticks = elapsed_microseconds.QuadPart;

		elapsed_microseconds.QuadPart *= 1'000'000;
		elapsed_microseconds.QuadPart /= frequency.QuadPart;

		_time = elapsed_microseconds.QuadPart;

		test.Finalize();
	}
};
