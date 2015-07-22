#include <mysql/harness/plugin.h>
#include <mysql/harness/logger.h>

#include <iostream>
#include <cstdlib>

#include <unistd.h>

static const char* requires[] = {
  "magic (>>1.0)",
  "logger",
};

static int init(AppInfo*) {
  extern void do_magic();
  do_magic();
  return 0;
}

static int deinit(AppInfo*) {
  return 0;
}

static void *start(AppInfo*) {
  for (int x = 0 ; x < 10 ; ++x) {
    log_info("<count: %d>", x);
    sleep(1);
  }
  return NULL;
}

Plugin example = {
  PLUGIN_ABI_VERSION,
  "An example plugin",
  VERSION_NUMBER(1,0,0),
  sizeof(requires)/sizeof(*requires),
  requires,
  0,
  NULL,
  init,
  deinit,
  start,
};

