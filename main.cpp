#include <iostream>
#include <map>
#include <chrono>
#include <jwt/jwt.hpp>

int main() {
  #ifdef testJWT
  using namespace jwt::params;
  jwt::jwt_object obj{algorithm("HS256"), secret("secret")};
  
  obj.add_claim("iss", "PetrPetrov")
     .add_claim("sub", "admin")
     .add_claim("id", "a-b-c-d-e-f-1-2-3")
     .add_claim("iat", 1513862371)
     .add_claim("exp", std::chrono::system_clock::now());
  
  std::error_code ec;
  obj = jwt::decode(enc_str, algorithms({"none", "HS256"}), ec, verify(false), secret("secret"));
  #endif
}
