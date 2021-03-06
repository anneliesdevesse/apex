#ifndef _APEX_SRC_TESTS_TESTMACROS_H_
#define _APEX_SRC_TESTS_TESTMACROS_H_

#include <QTest>

/**
 * @def TEST_COPY
 *
 * Performs a simple test for the copy constructor and assignment operator
 * of class @param C.
 *
 * @param C The class to test.
 *
 * @sa TEST_COPY_INIT
 */
#define TEST_COPY(C) TEST_COPY_INIT(C, (void))

/**
 * @def TEST_COPY_INIT
 *
 * Does the same as @ref TEST_COPY but lets you specify an init function to
 * initialise the data before it is copied.
 *
 * @param C    The class to test.
 * @param init The init function to use.
 *
 * @sa TEST_COPY
 */
#define TEST_COPY_INIT(C, init)                                                \
    do {                                                                       \
        QScopedPointer<C> orig(new C());                                       \
        init(orig.data());                                                     \
        C copy_ctor(*orig);                                                    \
        C copy_assign;                                                         \
        copy_assign = *orig;                                                   \
        QVERIFY(*orig == copy_ctor);                                           \
        QVERIFY(*orig == copy_assign);                                         \
        orig.reset();                                                          \
        QVERIFY(copy_assign == copy_ctor);                                     \
    } while (false)

/**
 * @def EXPECT_EXCEPTION
 *
 * Evaluates the given expression and calls QFAIL if no exception was thrown.
 */
#define EXPECT_EXCEPTION(expression)                                           \
    do {                                                                       \
        bool gotIt = false;                                                    \
        try {                                                                  \
            expression;                                                        \
        } catch (...) {                                                        \
            gotIt = true;                                                      \
        }                                                                      \
        if (!gotIt)                                                            \
            QFAIL("Expected an exception while executing " #expression);       \
    } while (false)

#endif // _APEX_SRC_TESTS_TESTMACROS_H_
