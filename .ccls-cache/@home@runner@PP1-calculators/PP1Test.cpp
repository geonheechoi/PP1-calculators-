/**************************************************************************************************/
// Test File for PP1
// Requires the Catch2 header file
// How to compile: g++ -std=c++17 -Wall -I$(CATCH_SINGLE_INCLUDE) (All cpp files)
// Example if Catch2 and source files are in this directory and at directory level: 
//    Example: g++ -std=c++17 -Wall *.cpp
// To see what tests were successful and failed, run your executable with the -s flag
//    Example: a.out -s
// A successful test should output: All tests passed (22 assertions in 1 test case)
/**************************************************************************************************/

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

#include "CalcList.hpp"

TEST_CASE("PP1: Test Cases for CalcList") {
  CalcList calc;

  SECTION("Total should be initially zero") {
    REQUIRE(calc.total() == 0.0l);
  }
//fail  error on removal-> removeLastoperation 함수 부분적으로만 작동 
  SECTION("Operations should be removable") {
    calc.newOperation(SUBTRACTION, 10);
    REQUIRE(calc.total() == -10.0l);

    calc.removeLastOperation();//이것만 안됨 not the end 출력된다는거는 부분적으로만 작동
  //removelast 수정필요
    REQUIRE(calc.total() == 0.0l);
  }
//fail error on removal 이랑 라스트오퍼 
  SECTION("Zero multiplication operation should be removable") {
    calc.newOperation(ADDITION, 50);
    calc.newOperation(MULTIPLICATION, 0);
//이하 줄부터 부분적으로만 작동됨
    calc.removeLastOperation();
    REQUIRE(calc.total() == 50.0l);
  }

  SECTION("Operations cannot divide by zero and should throw") {
    REQUIRE_THROWS(calc.newOperation(DIVISION, 0));

    REQUIRE_NOTHROW(calc.newOperation(SUBTRACTION, 10));
    REQUIRE_THROWS(calc.newOperation(DIVISION, 0));
  }



  SECTION("Removal of operations from an empty CalcList should throw") {
    REQUIRE_THROWS(calc.removeLastOperation());

    REQUIRE_NOTHROW(calc.newOperation(DIVISION, 10));
    REQUIRE_NOTHROW(calc.removeLastOperation());    //removl failed 
/*
PP1Test.cpp:54: FAILED:
  REQUIRE_NOTHROW( calc.removeLastOperation() ) 대놓고 리무브라스트 안된다고 되어있음
due to unexpected exception with message:
  Not the end
*/
    REQUIRE_THROWS(calc.removeLastOperation());
  }

  SECTION("toString functions should return string list of operations at precision") {
    calc.newOperation(ADDITION, 10);
    calc.newOperation(ADDITION, 20);
    calc.newOperation(SUBTRACTION, 20);
    calc.removeLastOperation();
    calc.newOperation(MULTIPLICATION, 1);

    std::string output = calc.toString(1);
    std::string outputShouldBe = 
    "3: 30.0*1.0=30.0\n2: 10.0+20.0=30.0\n1: 0.0+10.0=10.0\n";
    REQUIRE_THAT(output, Catch::Equals(outputShouldBe));

    output = calc.toString(3);
    outputShouldBe = 
    "3: 30.000*1.000=30.000\n2: 10.000+20.000=30.000\n1: 0.000+10.000=10.000\n";
    REQUIRE_THAT(output, Catch::Equals(outputShouldBe));
  }

  SECTION("Operations should change the total") {

/*
PP1Test.cpp:58: FAILED:
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should change the total
-------------------------------------------------------------------------------
PP1Test.cpp:76
...............................................................................

PP1Test.cpp:76: FAILED:
  {Unknown expression after the reported line}
due to unexpected exception with message:
  Not the end
함수 메세지  출력 그러나 라스트 오퍼레이션 지우기 안되는것으로 추정
  */
    double testTotal1, testTotal2, testTotal3, testTotal4;
    double tnAdd = rand() % 100 + 1;
    double tnMul = rand() % 100 + 1;
    double tnSub = rand() % 100 + 1;
    double tnDiv = rand() % 100 + 1;

    testTotal1 = 0 + tnAdd;
    testTotal2 = testTotal1 * tnMul;
    testTotal3 = testTotal2 - tnSub;
    testTotal4 = testTotal3 / tnDiv;

    calc.newOperation(ADDITION, tnAdd);
    REQUIRE(calc.total() == testTotal1);

    calc.newOperation(MULTIPLICATION, tnMul);
    REQUIRE(calc.total() == testTotal2);
    
    calc.newOperation(SUBTRACTION, tnSub);
    REQUIRE(calc.total() == testTotal3);

    calc.newOperation(DIVISION, tnDiv);
    REQUIRE(calc.total() == testTotal4);
//이하 줄 싹다 뉴오퍼 한줄 말고 안되는것으로 추정 18
    calc.removeLastOperation();
    REQUIRE(calc.total() == testTotal3);

    calc.removeLastOperation();
    REQUIRE(calc.total() == testTotal2);

    calc.removeLastOperation();
    REQUIRE(calc.total() == testTotal1);

    calc.removeLastOperation();
    REQUIRE(calc.total() == 0);
//이하 유일하게작동되는것으로 추정 
    calc.newOperation(ADDITION, 10);
    REQUIRE(calc.total() == 10);
  }
}
/*
2022/05/26 10:42 현재 테스트 상황 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
a.out is a Catch v2.2.3 host application.
Run with -? for options

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:25
...............................................................................

PP1Test.cpp:30: FAILED:
  REQUIRE( calc.total() == 0.0l )
with expansion:
  -10.0 == 0

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Zero multiplication operation should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:33
...............................................................................

PP1Test.cpp:38: FAILED:
  REQUIRE( calc.total() == 50.0l )
with expansion:
  0.0 == 50

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Removal of operations from an empty CalcList should throw
-------------------------------------------------------------------------------
PP1Test.cpp:50
...............................................................................

PP1Test.cpp:51: FAILED:
  REQUIRE_THROWS( calc.removeLastOperation() )
because no exception was thrown where one was expected:

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  toString functions should return string list of operations at precision
-------------------------------------------------------------------------------
PP1Test.cpp:58
...............................................................................

PP1Test.cpp:68: FAILED:
  REQUIRE_THAT( output, Catch::Equals(outputShouldBe) )
with expansion:
  "" equals: "3: 30.0*1.0=30.0
  2: 10.0+20.0=30.0
  1: 0.0+10.0=10.0
  "

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should change the total
-------------------------------------------------------------------------------
PP1Test.cpp:76
...............................................................................

PP1Test.cpp:101: FAILED:
  REQUIRE( calc.total() == testTotal3 )
with expansion:
  451.875 == 7230.0

===============================================================================
test cases:  1 | 1 failed
assertions: 14 | 9 passed | 5 failed

~/PP1-calculators$ cd
~/PP1-calculators$ g++ -std=c++17 *.cpp
~/PP1-calculators$ ./a.out

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
a.out is a Catch v2.2.3 host application.
Run with -? for options

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:25
...............................................................................

PP1Test.cpp:30: FAILED:
  REQUIRE( calc.total() == 0.0l )
with expansion:
  -10.0 == 0

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Zero multiplication operation should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:33
...............................................................................

PP1Test.cpp:38: FAILED:
  REQUIRE( calc.total() == 50.0l )
with expansion:
  0.0 == 50

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Removal of operations from an empty CalcList should throw
-------------------------------------------------------------------------------
PP1Test.cpp:50
...............................................................................

PP1Test.cpp:51: FAILED:
  REQUIRE_THROWS( calc.removeLastOperation() )
because no exception was thrown where one was expected:

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  toString functions should return string list of operations at precision
-------------------------------------------------------------------------------
PP1Test.cpp:58
...............................................................................

PP1Test.cpp:58: FAILED:
due to a fatal error condition:
  SIGSEGV - Segmentation violation signal

===============================================================================
test cases: 1 | 1 failed
assertions: 9 | 5 passed | 4 failed

Segmentation fault (core dumped)
~/PP1-calculators$ g++ -std=c++17 *.cpp
~/PP1-calculators$ ./a.out

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
a.out is a Catch v2.2.3 host application.
Run with -? for options

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:25
...............................................................................

PP1Test.cpp:25: FAILED:
  {Unknown expression after the reported line}
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Zero multiplication operation should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:33
...............................................................................

PP1Test.cpp:33: FAILED:
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Removal of operations from an empty CalcList should throw
-------------------------------------------------------------------------------
PP1Test.cpp:50
...............................................................................

PP1Test.cpp:54: FAILED:
  REQUIRE_NOTHROW( calc.removeLastOperation() )
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  toString functions should return string list of operations at precision
-------------------------------------------------------------------------------
PP1Test.cpp:58
...............................................................................

PP1Test.cpp:58: FAILED:
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should change the total
-------------------------------------------------------------------------------
PP1Test.cpp:76
...............................................................................

PP1Test.cpp:76: FAILED:
  {Unknown expression after the reported line}
due to unexpected exception with message:
  Not the end

===============================================================================
test cases:  1 |  0 passed | 1 failed
assertions: 16 | 11 passed | 5 failed

~/PP1-calculators$ g++ -std=c++17 *.cpp
~/PP1-calculators$ ./a.out

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
a.out is a Catch v2.2.3 host application.
Run with -? for options

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:25
...............................................................................

PP1Test.cpp:25: FAILED:
  {Unknown expression after the reported line}
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Zero multiplication operation should be removable
-------------------------------------------------------------------------------
PP1Test.cpp:33
...............................................................................

PP1Test.cpp:33: FAILED:
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Removal of operations from an empty CalcList should throw
-------------------------------------------------------------------------------
PP1Test.cpp:50
...............................................................................

PP1Test.cpp:54: FAILED:
  REQUIRE_NOTHROW( calc.removeLastOperation() )
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  toString functions should return string list of operations at precision
-------------------------------------------------------------------------------
PP1Test.cpp:58
...............................................................................

PP1Test.cpp:58: FAILED:
due to unexpected exception with message:
  Not the end

-------------------------------------------------------------------------------
PP1: Test Cases for CalcList
  Operations should change the total
-------------------------------------------------------------------------------
PP1Test.cpp:76
...............................................................................

PP1Test.cpp:76: FAILED:
  {Unknown expression after the reported line}
due to unexpected exception with message:
  Not the end

===============================================================================
test cases:  1 |  0 passed | 1 failed
assertions: 16 | 11 passed | 5 failed
16개 된듯
*/
/*
금요일까지 목표 

===============================================================================
All tests passed (22 assertions in 1 test case)
위의 메세지가 출력되게 만들어야함 
일기끝





*/