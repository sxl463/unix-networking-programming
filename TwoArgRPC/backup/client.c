#include	"test.h"		/* generated by rpcgen */

void test_RPCwrapper(int size, char* buf){
  CLIENT* cl;
  test_in in;
  test_out *outp;

  cl = Clnt_create("127.0.0.1", TEST_PROG, TEST_VERS, "tcp");

  in.arg1 = 5;
  in.arg3cstr = (char*)malloc(10);
  for(int i = 0; i < 5; i++)
    in.arg3cstr[i] = 's';
  in.arg3cstr[5] = '\0';

  if ( (outp = testproc_1(&in, cl)) == NULL)
    err_quit("%s", clnt_sperror(cl, 2));

  printf("result: %ld\n", outp->res1);

  //  testproc_1(&in, cl);

  free(in.arg3cstr);
}

void user(int times, int size) {
  int i = 0;
  char* buf = (char*)malloc(size+1);
  
  for(i = 0; i < size; i++) {
    buf[i] = (i%10) + '0';
  }
  buf[size] = '\0';

  for(i = 0; i < times; i++) {
    test_RPCwrapper(size,buf);
  }

  printf("%s\n", buf);

  free(buf);
}

int pseduo_main(int argc, char** argv) {
  if(argc != 3) {
    printf("Incorrect command-line arguments!\n");
    return 1;
  } 
  else {
    int times = atoi(argv[1]);
    int size = atoi(argv[2]);
    user(times,size);
    return 0;
  }
}

int
main(int argc, char **argv)
{
  //  CLIENT		*cl;
  //test_in	in;
  //test_out	*outp;

  if (argc != 3)
    err_quit("usage: client <hostname> <integer-value>");

  // cl = Clnt_create(argv[1], TEST_PROG, TEST_VERS, "tcp");

  //	if ( (outp = testproc_1(&in, cl)) == NULL)
  //		err_quit("%s", clnt_sperror(cl, argv[1]));

  //  testproc_1(&in, cl);

  //  printf("result: %ld\n", outp->res1);

  pseduo_main(argc, argv);

  exit(0);
}
