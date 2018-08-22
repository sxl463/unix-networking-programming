#include	"test.h"
#include <stdio.h>
#include <string.h>

void swap(char* buf, int i, int j) {
  char tmp = buf[i];
  buf[i] = buf[j];
  buf[j] = tmp;
	printf("swap: %s ", buf);
}

void service(int size, char* buf) {
  int i = 0;
  for(i = 1; i < size; i++) {
    swap(buf,0,i);
  }
	printf("\nservice end!\n");
}

test_out *
testproc_1_svc(test_in *inp, struct svc_req *rqstp)
{
	static test_out	out;

	out.res1 = inp->arg1 * inp->arg1;

	printf("server : %d\n", out.res1);
	printf("server : %s\n", inp->arg3cstr);

	service(strlen(inp->arg3cstr), inp->arg3cstr);

	return(&out);
}
