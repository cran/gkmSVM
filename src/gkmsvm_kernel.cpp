#include <Rcpp.h>
#include <string.h>
using namespace Rcpp;

#define MAX_LINE_WIDTH 10000	/* maximum line width */

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//
int mainGkmKernel(int argc, char** argv); 
  
// [[Rcpp::export]]
void gkmsvm_kernel(SEXP params){
  Rcpp::List rparam(params); // Get parameters in params.

  int L = Rcpp::as<int>(rparam["L"]);
  int K = Rcpp::as<int>(rparam["K"]);
  int maxnmm= Rcpp::as<int>(rparam["maxnmm"]);
  int maxseqlen= Rcpp::as<int>(rparam["maxseqlen"]);
  int maxnumseq= Rcpp::as<int>(rparam["maxnumseq"]);
  int useTgkm= Rcpp::as<int>(rparam["useTgkm"]);
  int alg= Rcpp::as<int>(rparam["alg"]);
  bool addRC= Rcpp::as<bool>(rparam["addRC"]);
  bool usePseudocnt= Rcpp::as<bool>(rparam["usePseudocnt"]);
  bool OutputBinary= Rcpp::as<bool>(rparam["OutputBinary"]);
  std::string posfile = Rcpp::as<std::string>(rparam["posfile"]);
  std::string negfile = Rcpp::as<std::string>(rparam["negfile"]);
  std::string outfile = Rcpp::as<std::string>(rparam["outfile"]);
  double wildcardLambda= Rcpp::as<double>(rparam["wildcardLambda"]);
  int wildcardMismatchM= Rcpp::as<int>(rparam["wildcardMismatchM"]);
  std::string alphabetFN = Rcpp::as<std::string>(rparam["alphabetFN"]);
  
  /*
   * 
   if(rparam["alphabetFN"]==NULL){
    printf("\n alphabetFN=null "); 
  }else{
    printf("\n alphabetFN=NOTnull "); 
  }
   */ 
    int argc=0; 
    char** argv = new char *[30]; 
    for(int i=0;i<30;i++){
      argv[i]=new char[5000]; 
    }
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "gkmsvm_kernel"); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-l"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", L); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-k"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", K); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-d"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", maxnmm); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-m"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", maxseqlen); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-n"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", maxnumseq); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-t"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", useTgkm); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-a"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", alg); 
    

    snprintf(argv[argc++],MAX_LINE_WIDTH, "-M"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", wildcardMismatchM); 
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-L"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%lf", wildcardLambda); 
    
    if(strcmp(alphabetFN.c_str(), "NULL")!=0){
      snprintf(argv[argc++],MAX_LINE_WIDTH, "-A"); 
      snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", alphabetFN.c_str()); 
    }

    if(addRC==false){
      snprintf(argv[argc++],MAX_LINE_WIDTH, "-R"); 
    }
    if(usePseudocnt==true){
      snprintf(argv[argc++],MAX_LINE_WIDTH, "-p"); 
    }
    
    if(OutputBinary==true){
      snprintf(argv[argc++],MAX_LINE_WIDTH, "-b"); 
    }
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", posfile.c_str()); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", negfile.c_str()); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", outfile.c_str()); 

    
    
   mainGkmKernel( argc, argv); 
   
   for(int i=0;i<30;i++){
     delete []argv[i]; 
   }
   delete[]argv;   
   
  }
  
  
/*
 *  I don't think this is needed, I guess Rccp takes care of it.
*/
// register with R 
  extern void gkmsvm_classify(SEXP params);
  #include <R_ext/Rdynload.h>
  static const
    R_CallMethodDef callMethods[] = {
      {"gkmSVM_gkmsvm_kernel", (DL_FUNC) &gkmsvm_kernel, -1},
      {"gkmSVM_gkmsvm_classify", (DL_FUNC) &gkmsvm_classify, -1},
      {NULL, NULL, 0}
    };
  
  void R_init_gkmSVM(DllInfo *info)
  {
   R_registerRoutines(info,
                       NULL, callMethods,
                       NULL, NULL);
  }
 /**/
