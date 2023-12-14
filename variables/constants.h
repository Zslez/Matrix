#define warning std::cout << WARNING
#define error std::cout << ERROR
#define passed std::cout << testCount++ << " - " << PASSED
#define notpassed std::cout << testCount++ << " - " << NOTPASSED

const char *WARNING = "\n\033[1;33mWARNING\033[0m: ";
const char *ERROR = "\n\033[1;31mERROR\033[0m: ";
const char *PASSED = "\033[1;32mTEST PASSED\033[0m: ";
const char *NOTPASSED = "\033[1;31mTEST NOT PASSED\033[0m: ";
