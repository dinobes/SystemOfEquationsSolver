Num_test :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp Num_test.cpp -o Num_test.exe

add_test :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp add_test.cpp -o add_test.exe

multi_test :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp multi_test.cpp -o multi_test.exe

se_test1 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp SysEq_test1.cpp -o SysEq_test1.exe

se_test2 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test2.cpp -o se_test2.exe

se_test3 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test3.cpp -o se_test3.exe

se_test4 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test4.cpp -o se_test4.exe

se_test5 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test5.cpp -o se_test5.exe

se_test6 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test6.cpp -o se_test6.exe

se_test7 :
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp lmath.cpp SysEq.cpp se_test7.cpp -o se_test7.exe

main:
				g++ -Wall -Werror -pedantic -g --std=c++11 Num.cpp main.cpp -o main.exe

clean :
				rm -rvf *.exe *~ *.out *.dSYM *.stackdump