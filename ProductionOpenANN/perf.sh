/usr/lib/linux-tools/5.4.0-146-generic/perf record -o logs/perflogs/PerfLog.data ./bin/CoreANN
/usr/lib/linux-tools/5.4.0-146-generic/perf report -i logs/perflogs/PerfLog.data
