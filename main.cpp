#include <iostream>
#include <jwt/jwt.hpp>

int main() {
#ifdef testJWT
  using namespace jwt::params;
  const char* enc_str =
    "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE1MTM4NjIzNzEsImlkIjoiYS1iLWMtZC1lLWYtMS0yLTMiLCJpc3MiOiJhcnVuLm11cmFsaWRoYXJhbiIsInN1YiI6ImFkbWluIn0.jk7bRQKTLvs1RcuvMc2B_rt6WBYPoVPirYi_QRBPiuk";
  std::error_code ec;
  auto obj = jwt::decode(enc_str, algorithms({"none", "HS256"}), ec, verify(false), secret("secret"));
#endif
}
