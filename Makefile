inc = -I ../include/

all:
	g++ -std=c++17 testJWT.cpp jwt.hpp -lcppunit -o test
test:
	chmod +x test
clean:
	$(RM) test
