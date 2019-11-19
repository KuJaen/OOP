//
// Created by 김혁진 on 2019/11/12.
//

#include "Integer.h"
#include "Float.h"
#include "Complex.h"
#include <iostream>

int main() {
    // 이번 과제는 테스트 코드를 주지 않습니다.
    // 직접 코드를 작성해보면서 확인해보세요
    {
        Number *a = new Integer(13);
        Number *result = a->add(new Float(3.14));

        std::cout << dynamic_cast<Float *>(result)->val() << std::endl; // 16.14
    }
    {
        Number *a = new Integer(3);
        Number *result = a
                ->add(new Float(3.14))
                ->sub(new Integer(1))
                ->mul(new Integer(7))
                ->sub(new Complex(11, 5));

        std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 24.980000 - 5.000000i
    }
    {
	Number *a = new Float(5.16);
	Number *result = a
		->add(new Integer(3)) // Float객체의 덧셈 테스트
		->sub(new Float(2.24)) // Float객체의 뺄셈 테스트
		->mul(new Integer(2)) // Float객체의 곱셈 테스트
		->div(new Integer(3)) // Float객체의 나눗셈 테스트
		->mul(new Complex(5.2, 1.6)); // Float객체와 복소수의 연산 테스트

	std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 20.522665 + 6.314667i
    }
    {
	Number *a = new Complex(3.14, 17);
	Number *result = a
		->add(new Float(5.15)) // Complex객체의 덧셈 테스트
		->mul(new Integer(2)) // Complex객체의 곱셈 테스트
		->div(new Float(3.5)); // Complex객체의 나눗셈 테스트

	std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 4.737143 + 9.714286i
    }
    {
	Number *a = new Complex(2.15, 1.5);
	Number *result = a
		->add(new Complex(7.2, 4.31)) // Complex객체 간의 덧셈
		->sub(new Complex(2.41, 3.8)) // Complex객체 간의 뺄셈
		->mul(new Complex(3.11, 9.1)); // Complex객체 간의 곱셈

	std::cout << dynamic_cast<Complex *>(result)->to_string() << std::endl; // 3.292400 + 69.405106i
    }
    // 테스트 코드 작성해보고 확인해보세요
    // 채점은 임의의 테스트코드로 진행할 예정입니다

    return 0;
}
