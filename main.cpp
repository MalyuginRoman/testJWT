#include <iostream>
#include <jwt/jwt.hpp>

int main() {
#ifdef testJWT
  using namespace jwt::params;
  const char* inv_enc_str =
    "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJpYXQiOjE1MTM4NjIzNzEsImlkIjoiYS1iLWMtZC1lLWYtMS0yLTMiLCJpc3MiOiJhcnVuLm11cmFsaWRoYXJhbiIsInN1YiI6ImFkbWluIn0.jk7bRQKTLvs1RcuvMc2B_rt6WBYPoVPirYi_QRBPiuk";
  std::error_code ec;
  auto obj = jwt::decode(enc_str, algorithms({"none", "HS256"}), ec, verify(false), secret("secret"));
  ASSERT_FALSE (ec);

  EXPECT_TRUE (obj.has_claim("iss"));
  EXPECT_TRUE (obj.payload().has_claim_with_value("iss", "arun.muralidharan"));

  //Case sensitive search
  EXPECT_FALSE (obj.has_claim("IAT"));
  EXPECT_TRUE (obj.payload().has_claim_with_value(jwt::registered_claims::issued_at, 1513862371));

  EXPECT_FALSE (obj.payload().has_claim_with_value(jwt::registered_claims::issued_at, 1513862372));
#endif
}
