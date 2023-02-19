#include "llvm/ADT/Statistic.h"
#include "llvm/IR/Function.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;

#define DEBUG_TYPE "hello"

STATISTIC(HelloCounter, "Counts number of functions greeted");

namespace {
  // Karm - The first implementation, without getAnalysisUsage.
  struct Karm : public FunctionPass {
    static char ID; // Pass identification, replacement for typeid
    Karm() : FunctionPass(ID) {}

    bool runOnFunction(Function &F) override {
      ++HelloCounter;
      errs() << "Karm: ";
      errs().write_escaped(F.getName());
      errs() << " Id: " << HelloCounter << '\n';

      return false;
    }
  };
}

char Karm::ID = 0;
static RegisterPass<Karm> X("karm", "Pass created by Karm");

// namespace {
//   // Hello2 - The second implementation with getAnalysisUsage implemented.
//   struct Hello2 : public FunctionPass {
//     static char ID; // Pass identification, replacement for typeid
//     Hello2() : FunctionPass(ID) {}

//     bool runOnFunction(Function &F) override {
//       ++HelloCounter;
//       errs() << "Hello: ";
//       errs().write_escaped(F.getName()) << '\n';
//       return false;
//     }

//     // We don't modify the program, so we preserve all analyses.
//     void getAnalysisUsage(AnalysisUsage &AU) const override {
//       AU.setPreservesAll();
//     }
//   };
// }

// char Hello2::ID = 0;
// static RegisterPass<Hello2>
// Y("hello2", "Hello World Pass (with getAnalysisUsage implemented)");
