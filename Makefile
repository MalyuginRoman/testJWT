all:
	g++ -std=c++17 testJWT.cpp -lcppunit -lcppjwt -o test
test:
	chmod +x test
clean:
	$(RM) test
