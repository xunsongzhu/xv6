#include "kernel/types.h"
#include "user.h"
/**
 * @className  sleep 
 * @author  SoraNimi
 * @date 2022/3/6 5:24 PM 
 * @version 1.0
 */

int main(int argc, char *argv[]) {
  if (argc < 2) {
	fprintf(2, "usage: sleep need more params");
  }
  int sleepTime = atoi(argv[1]);
  sleep(sleepTime);
  exit(0);
}