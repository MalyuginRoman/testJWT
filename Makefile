all:
	g++ -std=c++17 testJWT.cpp -lcppunit -ljwt-cpp -o test
test:
	chmod +x test
clean:
	$(RM) test
