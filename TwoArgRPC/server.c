#include	"test.h"
#include <stdio.h>
#include <string.h>

void swap(char* buf, int i, int j) {
  char tmp = buf[i];
  buf[i] = buf[j];
  buf[j] = tmp;
 // printf("swap: %s ", buf);
}

void service(int size, char* buf) {
  int i = 0;
  for(i = 1; i < size; i++) {
    swap(buf,0,i);
  }
  printf("\nservice end! size = %d\n", size);
}

test_out *
testproc_1_svc(test_in *inp, struct svc_req *rqstp)
{
	static test_out	out;

//	printf("server : %s\n", inp->arg);

	service(strlen(inp->arg2), inp->arg2);

	out.res1 = strlen(inp->arg2);
	return(&out);
}
