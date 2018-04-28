#include <assert.h>

int NullAccess()
{
    int *nullAccess = nullptr;
    assert(nullAccess != nullptr); // I want this to not end the nullAccess == nullptr path
    return *nullAccess;
}

static bool initialized = true;

int Initialized()
{
    assert(initialized); // I want this to be detected as an obvious defect if the caller has set the value to false
    return 3;
}

int main()
{
    initialized = false;
    int retVal = Initialized();
    retVal |= NullAccess();
    return retVal;
}
