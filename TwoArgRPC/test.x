struct test_in {		/* input (argument) */
  int arg1;
  string arg2<100000>;
};

struct test_out {		/* output (result) */
  long	res1;
};


program TEST_PROG {
    version TEST_VERS {
	test_out	TESTPROC(test_in) = 1; /* procedure number = 1 */
    } = 1;				/* version number */
} = 0x31230000;			/* program number */
