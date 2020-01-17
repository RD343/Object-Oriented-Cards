COMPILER = c++  

DRIVER = CardDeckMain
FILE1 = Card
FILE2 = Deck

$(DRIVER) : $(DRIVER).o   #the first character on the next line is a tab 
	$(COMPILER) -o  $(DRIVER) $(DRIVER).o 

$(DRIVER).o :  $(DRIVER).cpp  $(FILE1).h $(FILE1).cpp $(FILE2).h $(FILE2).cpp
	$(COMPILER) -c  $(DRIVER).cpp

clean:
	 rm -f CardDeckMain.o
