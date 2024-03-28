#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <cmath>

#include "doctest.h"
#include "double_vector.h"

#define epsilon 0.0001

TEST_CASE("double vector testing") {

  using namespace std;

  SUBCASE("edge cases") {

    double_vector dv = double_vector(1.0, 1.0);
    CHECK(2.0 == dot_product(dv, dv));

    double am = magnitude(dv);
    double srt = sqrt(2.0);
    double answer = fabs(srt - am);
    CHECK(answer < epsilon);

    double answer_acos = cosine_distance(dv, dv);

    CHECK(answer_acos < epsilon);

    double_vector a = double_vector(1.0, 0.0);
    double_vector b = double_vector(-1.0, 0.0);
    double answer_acos_a_b = cosine_distance(a, b);

    CHECK(M_PI == answer_acos_a_b);

    double_vector c = double_vector(2.7, 7.0);
    double_vector c_id = c;
    double answer_acos_c_c_id = cosine_distance(c, c_id);

    double actual_dot_prod_c = dot_product(c, c_id);
    CHECK(56.29 == actual_dot_prod_c);

    double actual_magnitude_c = magnitude(c);
    double actual_magnitude_c_id = magnitude(c_id);

    CHECK(actual_magnitude_c == actual_magnitude_c_id);

  }
}



