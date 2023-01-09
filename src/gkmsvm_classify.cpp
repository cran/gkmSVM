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
int mainSVMclassify(int argc, char** argv); 
  
// [[Rcpp::export]]
void gkmsvm_classify(SEXP params){
  Rcpp::List rparam(params); // Get parameters in params.

  int L = Rcpp::as<int>(rparam["L"]);
  int K = Rcpp::as<int>(rparam["K"]);
  int maxnmm= Rcpp::as<int>(rparam["maxnmm"]);
  int maxseqlen= Rcpp::as<int>(rparam["maxseqlen"]);
  int maxnumseq= Rcpp::as<int>(rparam["maxnumseq"]);
  int batchSize= Rcpp::as<int>(rparam["batchSize"]);
  int useTgkm= Rcpp::as<int>(rparam["useTgkm"]);
  int alg= Rcpp::as<int>(rparam["alg"]);
  bool addRC= Rcpp::as<bool>(rparam["addRC"]);
  bool usePseudocnt= Rcpp::as<bool>(rparam["usePseudocnt"]);
  std::string seqfile = Rcpp::as<std::string>(rparam["seqfile"]);
  std::string svseqfile = Rcpp::as<std::string>(rparam["svseqfile"]);
  std::string alphafile = Rcpp::as<std::string>(rparam["alphafile"]);
  std::string outfile = Rcpp::as<std::string>(rparam["outfile"]);
  double wildcardLambda= Rcpp::as<double>(rparam["wildcardLambda"]);
  int wildcardMismatchM= Rcpp::as<int>(rparam["wildcardMismatchM"]);
  std::string alphabetFN = Rcpp::as<std::string>(rparam["alphabetFN"]);
 
   
    int argc=0; 
    char** argv = new char *[30]; 
    for(int i=0;i<30;i++){
      argv[i]=new char[5000]; 
    }
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "gkmsvm_classify"); 
    
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
    
    snprintf(argv[argc++],MAX_LINE_WIDTH, "-b"); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%d", batchSize); 

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

    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", seqfile.c_str()); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", svseqfile.c_str()); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", alphafile.c_str()); 
    snprintf(argv[argc++],MAX_LINE_WIDTH, "%s", outfile.c_str()); 

    mainSVMclassify( argc, argv); 
   
   for(int i=0;i<30;i++){
     delete []argv[i]; 
   }
   delete[]argv;   
   
}
  
