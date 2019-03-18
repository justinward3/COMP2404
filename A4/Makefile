OBJ = main.o ShopController.o View.o Shop.o CustomerList.o VehicleList.o MechanicArray.o Mechanic.o Person.o Customer.o Vehicle.o

mechanicshop:	$(OBJ)
	g++ -o mechanicshop $(OBJ)

main.o:	main.cc
	g++ -g -c main.cc

ShopController.o:	ShopController.cc ShopController.h Shop.h View.h
	g++ -g -c ShopController.cc

View.o:	View.cc View.h
	g++ -g -c View.cc

Shop.o:	Shop.cc Shop.h CustomerList.h
	g++ -g -c Shop.cc

CustomerList.o: CustomerList.cc CustomerList.h Customer.h Person.h defs.h
	g++ -g -c CustomerList.cc

VehicleList.o:	VehicleList.cc VehicleList.h Vehicle.h defs.h
	g++ -g -c VehicleList.cc

Customer.o:	Customer.cc Customer.h Person.h
	g++ -g -c Customer.cc

Person.o: Person.cc Person.h
	g++ -g -c Person.cc

Mechanic.o: Mechanic.cc Mechanic.h
	g++ -g -c Mechanic.cc

MechanicArray.o: MechanicArray.cc MechanicArray.h
	g++ -g -c MechanicArray.cc

Vehicle.o: Vehicle.cc Vehicle.h
	g++ -g -c Vehicle.cc

clean:
	rm -f $(OBJ) mechanicshop
