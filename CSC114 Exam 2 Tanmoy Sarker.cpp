/******************************************************************************
CSC114-450 Computer Science I (Fall 2019 S1)
Exam 2
Tanmoy Sarker
*******************************************************************************/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    
    //Variable Declaration
    double num_of_pizzas, num_of_drinks, num_of_sodas, num_of_milkshakes, total_num_of_pizzas, total_num_of_sodas, total_num_of_milkshakes;
    char drinkchoice;
    const double unit_price_of_soda = 1.75;
    const double unit_price_of_milkshake = 4.50;
    const double unit_price_of_pizza = 12.00;
    const double tax = 0.06;
    double total_price_of_pizza, total_price_of_soda, total_price_of_milkshake, subtotal, totaltax, total;
    
    cout <<"Welcome to Pizza World!" << endl;
    
    while (num_of_pizzas != 7777 && num_of_drinks != 7777)
    {
        cout << "(You can enter 7777 for number of pizzas or drinks to exit this program and calculate your total bill)" << endl;
        
        cout << "How many pizzas would you like? "; //Prompting user to enter number of pizzas
        cin >> num_of_pizzas;
        
        while (num_of_pizzas < 0) //Input Validation for the number of pizzas
        {
            cout << "That's an invalid number of pizzas. Try again: ";
            cin >> num_of_pizzas;
        }
        
        if (num_of_pizzas != 0 & num_of_pizzas != 7777) //Neither of these cases yields a situation where num_of_pizzas needs to be updated
        {
            cout << "Your chose to order " << num_of_pizzas << " pizzas." << endl; //Display the number of pizzas the user ordered
            total_num_of_pizzas += num_of_pizzas; //Add to the number of pizzas ordered so far
        
        }

        cout << "How many drinks would you like? "; //Prompting user to enter number of drinks
        cin >> num_of_drinks;
        
        while (num_of_drinks < 0) //Input Validation for the number of drinks
        {
            cout << "That's an invalid number of drinks. Try again: ";
            cin >> num_of_drinks;
        }
        
        if (num_of_drinks != 0 && num_of_drinks != 7777) //Neither of these cases yields a situation where num_of_sodas or num_of_drinks needs to be updated
        {
            cout << "Your chose to order " << num_of_drinks << " drinks. "; //Display the number of drinks the user just ordered
            cout << "Press 'S' for sodas and 'M' for milkshakes: "; //Prompting user to choose type of drink
            cin >> drinkchoice;
            
            while (drinkchoice != 'S' && drinkchoice != 'M') //Input Validation for choice of drink
            {
                cout << "Please enter either 'S' for sodas or 'M' for milkshakes: ";
                cin >> drinkchoice;
            }
            
            if (drinkchoice == 'S' )
            {
                total_num_of_sodas += num_of_drinks; //Add to the number of sodas ordered so far
            }
            
            else if (drinkchoice == 'M' )
            {
                total_num_of_milkshakes += num_of_drinks; //Add to the number of milkshakes ordered so far
            }
        }
        
    }
    
    //Final calculation of accumulated sums
    
    total_price_of_pizza =  total_num_of_pizzas*unit_price_of_pizza;
    total_price_of_soda = total_num_of_sodas*unit_price_of_soda;
    total_price_of_milkshake = total_num_of_milkshakes*unit_price_of_milkshake;
    subtotal = total_price_of_pizza + total_price_of_soda + total_price_of_milkshake;
    totaltax = tax*subtotal;
    total = subtotal + totaltax;
    
    //Display the itemized bill
    
    cout << endl;
    cout << "############################" << endl;
    cout << "Your itemized bill: " << endl;
    cout << "Pizzas: " << fixed << setprecision(0) << total_num_of_pizzas << " * $" << fixed << setprecision(2) <<  unit_price_of_pizza << " = $" << total_price_of_pizza << endl;
    cout << "Sodas: " << fixed << setprecision(0) << total_num_of_sodas << " * $" << fixed << setprecision(2) << unit_price_of_soda << " = $" << total_price_of_soda << endl;
    cout << "Milkshakes: " << fixed << setprecision(0) << total_num_of_milkshakes << " * $" << fixed << setprecision(2) << unit_price_of_milkshake << " = $" << total_price_of_milkshake << endl;
    
    cout << "-----------------------------" << endl;
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax: $" << totaltax << endl;
    cout << "Total $" << total << endl;
    
    return 0;
}
