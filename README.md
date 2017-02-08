# BSLogger - extremely simple logger for C++

## Overview

The idea behind BSlogger is to provide an elementary logging class for C++ projects that don't need any advanced logging features.

BSlogger is:

  * header only
  * single class
  * very low overhead

BSlogger supports:

  * colored output
  * time and snapshot logging
  * several log levels, log level control
  * automatic function info

## Example usage

Basically all the features are shown in bslogger_examples.cpp

```
  LOG_INIT_CERR();

  // Log some stuff. The initial loglevel is
  // INFO and lower (INFO, WARNING, ERROR)
  // so the debug info is not displayed
  log(LOG_DEBUG) << "Some text\n";
  log(LOG_INFO) << "Some text\n";
  log(LOG_WARN) << "Some text\n";
  log(LOG_ERR) << "Some text\n";

  // Change the log level
  log.set_log_level(LOG_DEBUG);

  // Now the debug info is displayed
  log(LOG_DEBUG) << "Some text\n";

  // Everything that has a operator<< method
  // for ostreams can be logged
  float x = 3.1415;

  log(LOG_DEBUG) << "The value of x is " << x
                 << ", the address is " << &x
                 << '\n';

  // You can add time snapshots
  log.add_snapshot("before_sleep");
  std::this_thread::sleep_for(std::chrono::milliseconds(2000));
  
  // Log the time since the last snap added
  log.time_since_last_snap();

  // Log the time since a particular snap was added
  log.time_since_snap("before_sleep");

  // Log the time since the log was initialized
  log.time_since_start();
```

Output:

```
[ INFO    ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: Some text
[ WARNING ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: Some text
[ ERROR   ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: Some text
[ DEBUG   ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: Some text
[ DEBUG   ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: The value of x is 3.1415, the address is 0x7fff17d6f1d8
[ TIME    ][ 2017-02-08T20:04:47 ][ int main(int, char**) ]: Added snap 'before_sleep'
[ TIME    ][ 2017-02-08T20:04:49 ][ int main(int, char**) ]: 2s since snap 'before_sleep'
[ TIME    ][ 2017-02-08T20:04:49 ][ int main(int, char**) ]: 2s since snap 'before_sleep'
[ TIME    ][ 2017-02-08T20:04:49 ][ int main(int, char**) ]: 2s since instantiation
```

## Advanced usage

The macros `LOG_INIT_COUT()`, `LOG_INIT_CERR()` and `LOG_INIT_CLOG()` are shorthands for `logger log(std::cout, __PRETTY_FUNCTION__)`, `logger log(std::cerr, __PRETTY_FUNCTION__)` and `logger log(std::clog, __PRETTY_FUNCTION__)`. Any `std::ostream` can be passed to the `logger()` constructor. The two constructors are:

  * `logger(std::ostream&, std::string)` - contructs a BSlogger logging to `ostream` and presenting the supplied string as the namespace.
  * `logger(std::ostream&, unsigned, std::string)` - construcs a BSlogger using a non default log-level, otherwise same as above.

The log levels are:

  * `LOG_SILENT`
  * `LOG_ERR`
  * `LOG_WARN`
  * `LOG_INFO`
  * `LOG_TIME`
  * `LOG_DEBUG`

The logger will print all messages with the current level and lower. The default log-level is `LOG_TIME`, the log-level can be modified using the `logger::set_log_level(unsigned)` function.

The compiler definition `-DBSLOG_NO_COLORS` will turn off colored output.
If one wants to modify the colors, simply replace the `BSLOG_*` definitions in the header file.