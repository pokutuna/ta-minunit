#define mu_failed(file,line,expr) fprintf(stderr, "%s:%u: failed assertion `%s'\n",file,line,expr)
#define mu_tested(test,passed) fprintf(stderr, "Test %-10s : %s\n",test,(passed)?"passed":"FAILED")
#define mu_assert(expr) do{mu_nassert++;if(!(expr)){++mu_nfail;mu_failed(__FILE__,__LINE__,#expr);}else{fprintf(stderr, ".");}}while(0)
#define mu_run_test(test) do{int f=mu_nfail;++mu_ntest;test();mu_tested(#test,(f==mu_nfail));}while(0)
#define mu_show_failures() do{if(mu_nfail){fprintf(stderr, "### FAILED %d of %d asserts (%d tests).\n",mu_nfail,mu_nassert,mu_ntest);}else{fprintf(stderr, "### Passed All Tests (%d asserts, %d tests)\n", mu_nassert, mu_ntest);}}while(0)
extern int mu_nfail;
extern int mu_ntest;
extern int mu_nassert;
