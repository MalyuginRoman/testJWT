all:
	g++ -std=c++17 main.cpp -o main
	g++ -std=c++17 testJWT.cpp -lcppunit -o testJWT
test:
	chmod +x main
	./testJWT
clean:
	$(RM) main testJWT
