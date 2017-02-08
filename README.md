# BSLogger - extremely simple logger for C++

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

  // Log the time since the last snap added
  log.time_since_last_snap();

  // Log the time since a particular snap was added
  log.time_since_snap("before_sleep");

  // Log the time since the log was initialized
  log.time_since_start();
```

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