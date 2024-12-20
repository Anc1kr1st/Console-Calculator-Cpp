#include "Calculator.h"

Calculator::Calculator()
{
	trigono = EMPTY;
	hyperbolic = NICHTS;
	power = VACANT;
	errorgama = CLEAR;
	myStandard = DEG;
}

bool Calculator::Menu()
{
	system("cls");
	
	std::cout << "MENU\n";
	std::cout << "1. Basic Mathematical Operators\n";
	std::cout << "2. Trigonometric Operators\n";
	std::cout << "3. Hyperbolic Operators\n";
	std::cout << "4. Power Functions\n";
	std::cout << "5. Error and gamma functions\n";
	std::cout << "6. RAD / DEG / GRA\n";
	std::cout << "7. Exit\n\n";

	std::cout << "Your choice: ";

	int choice = 0;
	std::cin >> choice;

	switch (choice)
	{
	case 1: BasicMathematicalOperators();
		break;
	case 2: TrigonometricOperators();
		break;
	case 3: HyperbolicOperators();
		break;
	case 4: PowerFunctions();
		break;
	case 5: ErrorGammaFunctions();
		break;
	case 6: DegRadGrad();
		break;
	case 7: exit(0);
		break;

	default: std::cerr << "Wrong input. Press any key to continue and then confirm by pressing enter." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		char anyKey;
		std::cin >> anyKey;
		break;
	}
	
 return true;
}

// 1
void Calculator::BasicMathematicalOperators()
{
	double localNumber1;
	double localNumber2;
	double localNumber3 = 0;
	char localSymbol;
	int  mathOperator = 0;
	int localCD = 0;

	while (true)
	{
		if (localCD == 0)
		{
			std::cout << "Enter number: \n";
			std::cin >> localNumber1;
			localCD++;
		}

		std::cout << "Enter symbol (+, -, *, /) or = for result: \n";
		std::cin >> localSymbol;
		std::cin.get();

		

		switch (localSymbol)
		{
		case '+': 	
			std::cout << "Enter number: \n";
			std::cin >> localNumber2;
			localNumber3 = localNumber2 + localNumber1;
			localNumber1 = localNumber3;
			break;
		case '-': 
			std::cout << "Enter number: \n";
			std::cin >> localNumber2;
			localNumber3 = localNumber2 - localNumber1;
			localNumber1 = localNumber3;
			break;
		case '*': 
			std::cout << "Enter number: \n";
			std::cin >> localNumber2;
			localNumber3 = localNumber2 * localNumber1;
			localNumber1 = localNumber3;
			break;
		case '/': 
			std::cout << "Enter number: \n";
			std::cin >> localNumber2;
			localNumber3 = localNumber1 / localNumber2;
			localNumber1 = localNumber3;
			break;
		case '=': 
			std::cout << "Result: " << localNumber3 << std::endl;
			std::cout << "Do you want to return to menu? Y/N " << std::endl;
			std::cin >> localSymbol;
			std::cin.get();
			if (localSymbol == 'y' || localSymbol == 'Y')
			{
				Menu();
				break;
			}
			else if (localSymbol == 'n' || localSymbol == 'N')
			{
				BasicMathematicalOperators();
			}
			else
			{
				std::cerr << "Wrong input. Do you want to return to menu? Y/N" << std::endl;
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cin >> localSymbol;
				std::cin.get();
				break;
			}	
		default:
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cerr << "Wrong symbol. \n";
			std::cout << "Enter symbol (+, -, *, /) or = for result: \n";
			std::cin >> localSymbol;
			std::cin.get();
			break;
		}
	}
}

void Calculator::TrigonometricOperators()
{
	double localNumber1;
	int localChoice;
	char backToMenu;

	std::cout << "\nEnter number: ";
	// std::cin >> localNumber1;

	while (!(std::cin >> localNumber1)) {
		std::cout << "Invalid input. Please enter number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "\nChoose function: \n";
	std::cout << "1. Sine \n"
		"2. Cosine \n"
		"3. Tangent \n"
		"4. Arcsine \n"
		"5. Arccosine \n"
		"6. Arctangent \n\n";

		while (!(std::cin >> localChoice)) {
			std::cout << "Invalid input. Please enter an integer: ";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

	if (myStandard == DEG)
	{

		const double PI = 3.14159265358979323846;
		localNumber1 = localNumber1 * (PI / 180.0);

	}
	else if (myStandard == GRAD)
	{
		const double ConvertGraToRad = 0.015708;
		localNumber1 = localNumber1 * ConvertGraToRad;
	}


		switch (localChoice)
		{
		case SIN: std::cout << "Result:" << sin(localNumber1) << std::endl;		// rad
			break;
		case COS:  std::cout << "Result:" << cos(localNumber1) << std::endl;		// rad
			break;
		case TAN:  std::cout << "Result:" << tan(localNumber1) << std::endl;		// rad
			break;
		case ASIN: std::cout << "Result:" << asin(localNumber1) << std::endl;	// rad
			break;
		case ACOS: std::cout << "Result:" << acos(localNumber1) << std::endl;	// rad
			break;
		case ATAN: std::cout << "Result:" << atan(localNumber1) << std::endl;	// rad
			break;
		default: std::cerr << "Wrong input." << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			break;
		}

		std::cout << "\nDo you want to return to menu? Y/N " << std::endl;
		std::cin >> backToMenu;
		std::cin.get();
		backToMenu = toupper(backToMenu);

		while (!(backToMenu == 'Y' || backToMenu == 'N')) {
			std::cout << "Invalid input. Please enter Y/N \n";
			std::cin.clear();
			// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cin >> backToMenu;
			std::cin.get();
			backToMenu = toupper(backToMenu);
		}

		if (backToMenu == 'Y')
		{
			Menu();
		}
		else if (backToMenu == 'N')
		{
			system("cls");
			TrigonometricOperators();
		}
}

void Calculator::HyperbolicOperators()
{

	double localNumber1;
	int localChoice;
	char backToMenu;

	std::cout << "Enter number: \n";
	//std::cin >> localNumber1;

	while (!(std::cin >> localNumber1)) {
		std::cout << "Invalid input. Please enter number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "\nChoose function: \n";
	std::cout << "1. Hyperbolic sine \n"
		"2. Hyperbolic cosine \n"
		"3. Hyperbolic tangent \n"
		"4. Hyperbolic sine area \n"
		"5. Hyperbolic cosine area \n"
		"6. Hyperbolic tangent area \n\n";

	//std::cin >> localChoice;
	while (!(std::cin >> localChoice)) {
		std::cout << "Invalid input. Please enter intiger: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	switch (localChoice)
	{
	case SINH: std::cout << "Result:" << sinh(localNumber1) << std::endl;
		break;
	case COSH:  std::cout << "Result:" << cosh(localNumber1) << std::endl;
		break;
	case TANH:  std::cout << "Result:" << tanh(localNumber1) << std::endl;
		break;
	case ASINH: std::cout << "Result:" << asinh(localNumber1) << std::endl;
		break;
	case ACOSH: std::cout << "Result:" << acosh(localNumber1) << std::endl;
		break;
	case ATANH: std::cout << "Result:" << atanh(localNumber1) << std::endl;
		break;
	default: std::cerr << "\nWrong input." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}

	std::cout << "\nDo you want to return to menu? Y/N " << std::endl;
	std::cin >> backToMenu;
	std::cin.get();
	backToMenu = toupper(backToMenu);

	while (!(backToMenu == 'Y' || backToMenu == 'N')) {
		std::cout << "Invalid input. Please enter Y/N \n";
		std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> backToMenu;
		std::cin.get();
		backToMenu = toupper(backToMenu);
	}

	if (backToMenu == 'Y')
	{
		Menu();
	}
	else if (backToMenu == 'N')
	{
		system("cls");
		HyperbolicOperators();
	}
}

void Calculator::PowerFunctions()
{
	double localNumber1;
	double localNumber2 = 3.0;
	int localChoice;
	char backToMenu;

	std::cout << "Enter number: ";
	//std::cin >> localNumber1;

	while (!(std::cin >> localNumber1)) {
		std::cout << "Invalid input. Please enter number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "\nChoose function: \n";
	std::cout << "1. To the second power \n"
		"2. To the third power \n"
		"3. To the n power \n"
		"4. Square 2 \n"
		"5. Cube root \n"
		"6. Square n \n"
		"7. Hypotenuse \n\n";

		//std::cin >> localChoice;
	while (!(std::cin >> localChoice)) {
		std::cout << "Invalid input. Please enter intiger: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	switch (localChoice)
	{
	case POW: std::cout << "Result:" << pow(localNumber1, localNumber1) << std::endl;
		break;
	case POWTHIRD:  std::cout << "Result:" << pow(localNumber1, localNumber2) << std::endl;
		break;
	case POWN: while (std::cout << "Enter exponet: " && !(std::cin >> localNumber2)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter.\n";
	}
			 std::cout << "Result:" << pow(localNumber1, localNumber2) << std::endl;
			 break;
	case SQRT: std::cout << "Result:" << sqrt(localNumber1) << std::endl;
		break;
	case CBRT:  std::cout << "Result:" << cbrt(localNumber1) << std::endl;
		break;
	case SQRTN:  while (std::cout << "Enter exponet: " && !(std::cin >> localNumber2)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter.\n";
	}
			  std::cout << "Result:" << pow(localNumber1, 1.0 / localNumber2) << std::endl;
			  break;
	case HYPOT: while (std::cout << "Enter exponet: " && !(std::cin >> localNumber2)) {
		std::cin.clear(); //clear bad input flag
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //discard input
		std::cout << "Invalid input, please re-enter.\n";
	}
			  std::cout << "Result:" << hypot(localNumber1, localNumber2) << std::endl;
			  break;
	default: std::cerr << "Something went wrong in the switch statement." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}

	std::cout << "\nDo you want to return to menu? Y/N " << std::endl;
	std::cin >> backToMenu;
	std::cin.get();
	backToMenu = toupper(backToMenu);

	while (!(backToMenu == 'Y' || backToMenu == 'N')) {
		std::cout << "Invalid input. Please enter Y/N \n";
		std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> backToMenu;
		std::cin.get();
		backToMenu = toupper(backToMenu);
	}

	if (backToMenu == 'Y')
	{
		Menu();
	}
	else if (backToMenu == 'N')
	{
		system("cls");
		PowerFunctions();
	}
}

void Calculator::ErrorGammaFunctions()
{

	double localNumber1;
	int localChoice;
	char backToMenu;

	std::cout << "\nEnter number: ";
	//std::cin >> localNumber1;

	while (!(std::cin >> localNumber1)) {
		std::cout << "Invalid input. Please enter number: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	std::cout << "Choose function: \n";
	std::cout << "1. Compute error function \n"
		"2. Compute complementary error function \n"
		"3. Compute gamma function \n"
		"4. Compute log-gamma function \n\n";

	//	std::cin >> localChoice;
	while (!(std::cin >> localChoice)) {
		std::cout << "Invalid input. Please enter intiger: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	switch (localChoice)
	{
	case ERF: std::cout << erf(localNumber1) << std::endl;
		break;
	case ERFC:  std::cout << erfc(localNumber1) << std::endl;
		break;
	case TGAMMA:  std::cout << tgamma(localNumber1) << std::endl;
		break;
	case LGAMMA: std::cout << lgamma(localNumber1) << std::endl;
		break;
	default: std::cerr << "Something went wrong in the switch statement." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		break;
	}

	std::cout << "\nDo you want to return to menu? Y/N " << std::endl;
	std::cin >> backToMenu;
	std::cin.get();
	backToMenu = toupper(backToMenu);

	while (!(backToMenu == 'Y' || backToMenu == 'N')) {
		std::cout << "Invalid input. Please enter Y/N \n";
		std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> backToMenu;
		std::cin.get();
		backToMenu = toupper(backToMenu);
	}

	if (backToMenu == 'Y')
	{
		Menu();
	}
	else if (backToMenu == 'N')
	{
		system("cls");
		ErrorGammaFunctions();
	}
}

void  Calculator::DegRadGrad()
{
	char localChoice;
	int change;

	std::cout << "Currently is ";
	
	switch (myStandard)
	{
	case DEG: std::cout << "DEGREE set.\n";
		break;
	case RAD:  std::cout << "RADIAN set.\n";
		break;
	case GRAD: std::cout << "GRADIAN set.\n";
		break;
	default:
		break;
	}

	std::cout << "\nWish you change settings? Y/N.\n";
	std::cin >> localChoice;
	std::cin.get();
	localChoice = toupper(localChoice);

	while (!(localChoice == 'Y' || localChoice == 'N')) {
		std::cout << "Invalid input. Please enter Y/N \n";
		std::cin.clear();
		// std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> localChoice;
		std::cin.get();
		localChoice = toupper(localChoice);
	}

		if (localChoice == 'y' || localChoice == 'Y')
		{
			std::cout << "1. Degree \n"
				"2. Rads \n"
				"3. Grads \n";
			std::cin >> change;

			switch (change)
			{
			case DEG: myStandard = DEG;
				break;
			case RAD:  myStandard = RAD;
				break;
			case GRAD:  myStandard = GRAD;
				break;
			default:
				break;
			}
			Menu();
		}
		else if (localChoice == 'n' || localChoice == 'N')
		{
			Menu();
		}
	
}















