inc = -I ../include/

all:
	g++ -std=c++17 testJWT.cpp -lcppunit -o test
test:
	chmod +x test
clean:
	$(RM) test
