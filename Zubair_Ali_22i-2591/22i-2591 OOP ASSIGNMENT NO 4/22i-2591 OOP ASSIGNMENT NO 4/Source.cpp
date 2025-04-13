#include<iostream>
using namespace std;

// Product class
class Product {
public:
	// Attributes
	string name; // product name
	int ID; // product ID
	int quantity; // product quantity
	int price; // product selling price
	int costprice; // product cost price

	// Default constructor
	Product() {
		name = "";
		ID = 0;
		quantity = 0;
		price = 0;
		costprice = 0;
	}

	// Parameterized constructor
	Product(string n, int q, int p, int id, int cp) {
		name = n;
		ID = id;
		quantity = q;
		price = p;
		costprice = cp;
	}

	// Setters
	void setname(string n) {
		name = n;
	}

	void setquantity(int q) {
		quantity = q;
	}

	void setID(int id) {
		ID = id;
	}

	void setprice(int p) {
		price = p;
	}

	// Getters
	string getname() {
		return name;
	}

	int getquantity() {
		return quantity;
	}

	int getID() {
		return ID;
	}

	int getprice() {
		return price;
	}
};

// Inventory class, inherits from Product class
class Inventory : public Product {
public:
	Product prod[100]; // array of products
	int noOfProduct; // number of products

	// Default constructor
	Inventory() {
		noOfProduct = 0;
	}

	// Parameterized constructor
	Inventory(int nop) {
		noOfProduct = nop;
	}

	// Setters
	void setnop(int nop) {
		noOfProduct = nop;
	}

	// Getters
	int getnop() {
		return noOfProduct;
	}

	// AddOrder method - adds a new product to the inventory
	void AddOrder(string name, int quantity, int price, int ID, int cp) {
		if (noOfProduct < 100) {
			prod[noOfProduct].name = name;
			prod[noOfProduct].ID = ID;
			prod[noOfProduct].quantity = quantity;
			prod[noOfProduct].price = price;
			prod[noOfProduct].costprice = cp;
			noOfProduct++;
		}
		else
			cout << "Sorry, inventory is full (100 products maximum)." << endl;
	}

	// DisplayOrder method - displays the details of a product with a given ID
	void DisplayOrder(int id) {
		for (int i = 0; i < noOfProduct; i++) {
			if (prod[i].ID == id) {
				cout << "Name: " << prod[i].name << endl;
				cout << "ID: " << prod[i].ID << endl;
				cout << "Quantity: " << prod[i].quantity << endl;
				cout << "Price: " << prod[i].price << endl;
				cout << "Cost Price: " << prod[i].costprice << endl;
			}
			else
				cout << "Invalid ID." << endl;
		}
	}

	// OrderProduct method - increases the quantity of a product with a given ID
	void OrderProduct(int ID, int quantity) {
		for (int i = 0; i < noOfProduct; i++) {
			if (prod[i].ID == ID) {
				prod[i].quantity += quantity;
				//	cout << "YOUR ORDER PRODUCT QUANTITY" << prod[i].quantity << endl;
				break;
			}
			else
				cout << "ID IS NOT MATCHED" << endl;
		}
	}
	// This function updates the product quantity and price when an order is taken
	void takeOrder(int ID, int quantity, int price) {
		for (int i = 0; i < noOfProduct; i++) {
			if (prod[i].ID == ID) {
				prod[i].quantity -= quantity;
				prod[i].price = price;
				// Commented out print statements
			}
			else
				cout << "ID IS NOT MATCHED" << endl;
		}
	}

	// This function updates the product price based on its ID
	void updatePrice(int ID, int price) {
		for (int i = 0; i < noOfProduct; i++) {
			if (prod[i].ID == ID) {
				prod[i].price = price;
				// Commented out print statement
				break;
			}
			else
				cout << "ID IS NOT MATCHED" << endl;
		}
	}

	// This function applies a discount to a product during Ramadan
	void RamadanDiscount(int ID, int disc) {
		if (disc > 0 && disc < 100) {
			for (int i = 0; i < noOfProduct; i++) {
				if (prod[i].ID == ID) {
					int overalldiscount = prod[i].getprice() - (prod[i].getprice() * disc) / 100;
					prod[i].setprice(overalldiscount);
					// Commented out print statement
					break;
				}
				else
					cout << "ID IS NOT MATCHED" << endl;
			}
		}
		else
			cout << "Dscount must be between 0 or 100 " << endl;
	}

	// This function applies a promotion discount to a product
	bool promotionDiscount(int ID, int promdiscount) {
		bool flag = false;
		for (int i = 0; i < noOfProduct; i++) {
			if (prod[i].ID == ID) {
				prod[i].setprice(promdiscount);
				// Commented out print statement
				flag = true;
				break;
			}
		}
		if (!flag)
			cout << "Invalid id" << endl;

		return flag;
	}

	// This function applies a market discount to a product
	void DynamicMarketPrice(int ID, int markdiscount) {
		if (markdiscount > 0 && markdiscount < 100) {
			for (int i = 0; i < noOfProduct; i++) {
				if (prod[i].ID == ID) {
					prod[i].setprice(markdiscount);
					// Commented out print statement
					break;
				}
				else
					cout << "ID IS NOT MATCHED " << endl;
			}
		}
		else
			cout << "Dscount must be between 0 or 100 " << endl;
	}

	// This function applies a volume discount to a product
	void VolumeDiscount(int ID, int quantity, int voldiscount) {
		if (voldiscount > 0 && voldiscount < 100) {
			for (int i = 0; i < noOfProduct; i++) {
				if (prod[i].ID == ID) {
					int totalprice = quantity * prod[i].getprice();
					int volDis = totalprice - (totalprice * voldiscount) / 100;
					prod[i].setprice(volDis);
					//	cout << "Volumn discount" << prod[i].getprice() << endl;
					break;
				}
				else
					cout << "Invalid ID " << endl;
			}
		}
		else
			cout << "Dscount must be between 0 or 100 " << endl;
	}

	// This function applies a shopping discount to a product with a given ID
	void shoppingDiscount(int ID, int shoppdiscount) {
		if (shoppdiscount > 0 && shoppdiscount < 100) {
			for (int i = 0; i < noOfProduct; i++) {
				if (prod[i].ID == ID) {
					// Calculate the discounted price
					int shoppDis = prod[i].getprice() - (prod[i].getprice() * shoppdiscount) / 100;
					// Set the new price for the product
					prod[i].setprice(shoppDis);
					break;
				}
				else
					cout << "Invalid ID " << endl;
			}
		}
		else
			cout << "Discount must be between 0 or 100 " << endl;
	}

	// This function returns the ID of a product with a given index
	int getItem(int id) {
		return prod[id].ID;
	}

	// This function returns the name of a product with a given index
	string getname(int id) {
		return prod[id].name;
	}
};

	// This class represents an item in a shopping cart
	class cartItem {
	public:
		string customername; // Name of the product
		int customerquantity; // Quantity of the product
		int customerprice; // Price of the product

		// Default constructor
		cartItem() {
			customername = "";
			customerquantity = 0;
			customerprice = 1;
		}

		// Constructor with parameters
		cartItem(string n, int q, int p) {
			customername = n;
			customerquantity = q;
			customerprice = p;
		}
	};

	// This class represents a shopping cart
	class Cart : public Product {
	public:
		Inventory* invent; // Pointer to the inventory
		int noCartitem; // Maximum number of items in the cart
		int cartno; // Number of items in the cart
		cartItem* cartquantity; // Array of cart items

		// Default constructor
		Cart() {
			noCartitem = 100;
			cartno = 0;
			invent = new Inventory[noCartitem];
			cartquantity = new cartItem[noCartitem];
			for (int i = 0; i < noCartitem; i++) {
				cartquantity[i] = cartItem();
			}
		}

		// Constructor with parameters
		Cart(int nc, int cartno) {
			noCartitem = nc;
			this->cartno = cartno;
			invent = new Inventory[noCartitem];
			cartquantity = new cartItem[noCartitem];
			for (int i = 0; i < noCartitem; i++) {
				cartquantity[i] = cartItem();
			}
		}

		// Set the name of a cart item at a given index
		void setcartname(string n, int ind) {
			cartquantity[ind].customername = n;
		}

		// Set the quantity of a cart item at a given index
		void setcartquantity(int q, int ind) {
			cartquantity[ind].customerquantity = q;
		}

		// Set the price of a cart item at a given index
		void setcartprice(int p, int ind) {
			cartquantity[ind].customerprice = p;
		}

		// Get the name of a cart item at a given index
		string getcartname(int ind) {
			return cartquantity[ind].customername;
		}
		// Returns the quantity of a particular product in the cart
		int getcartquantity(int ind) {
			return cartquantity[ind].customerquantity;
		}

		// Returns the price of a particular product in the cart
		int getcartprice(int ind) {
			return cartquantity[ind].customerprice;
		}

		// Adds an item to the cart, updates the inventory accordingly
		void AddcartItem(Inventory& inv, int id, int customerquantity) {
			for (int i = 0; i < inv.noOfProduct; i++) {
				if (inv.prod[i].ID == id) {
					if (inv.prod[i].quantity >= customerquantity) {
						// Set the details of the product in the cart
						cartquantity[i].customername = inv.prod[i].name;
						cartquantity[i].customerquantity += customerquantity;
						cartquantity[i].customerprice = inv.prod[i].price;

						// Update the inventory quantity
						inv.prod[i].quantity -= customerquantity;

						// Increase the cart item count
						cartno++;
					}
					else {
						cout << "Sorry sir we donot have a sufficient quantity" << endl;
					}
					break;
				}
			}
		}

		// Removes an item from the cart, updates the inventory accordingly
		void RemoveCartItem(Inventory inv, int cartid) {
			for (int i = 0; i < noCartitem; i++) {
				if (inv.prod[i].ID == cartid) {
					int quantity = cartquantity[i].customerquantity;
					invent->prod[i].quantity += quantity;
					cartquantity[i].customerquantity = 0;
					break;
				}
				else {
					cout << "ID not valid! " << endl;
				}
			}
		}

		// Applies a discount to a particular item in the cart
		void Discount(Inventory& inv, int cartItemId, int cartDiscount) {
			int totalDiscount = 0;
			bool foundItem = false;

			for (int i = 0; i < noCartitem; i++) {
				if (inv.prod[i].ID == cartItemId) {
					foundItem = true;
					int quantity = getcartquantity(i);
					int price = getcartprice(i);
					int total = quantity * price;

					// Get the type of discount and calculate the total discount
					cout << "Enter the discount type: ";
					string type;
					cin >> type;
					if (type == "BOGO") { // Buy One Get One free
						int freeDiscount = cartDiscount / 2;
						totalDiscount = freeDiscount * price;
						break;
					}
					else if (type == "percentage") {
						int percentage;
						cout << "Enter the discount percentage: ";
						cin >> percentage;
						totalDiscount = total * percentage / 100;
						break;
					}
					else {
						cout << "Sorry, " << type << " discount is not available" << endl;
						break;
					}
				}
			}

			// Check if the item was found in the cart
			if (!foundItem) {
				cout << "Invalid cart item ID" << endl;
				return;
			}
		}

		// Refunds a particular item in the cart 
		
		void refund(int id, string name, int refundquantity) {
		
		for (int i = 0; i < noCartitem; i++) {
			if (cartquantity[i].customername == name) {
				cartquantity[i].customerquantity -= refundquantity;
				invent->prod[i].quantity += refundquantity;
				//cout << "refund " << cartquantity[i].customerquantity << endl;
				break;
			}
			else
				cout << "Sorry refunding is not possible" << endl;
		}
	}

};
// Define a class named Repository
class Repository {
public:

	// Declare pointers to Inventory and Cart objects
	Inventory* invent;
	Cart* cart;

	// Declare a variable to store the number of sales
	int noofsales;

	// Default constructor
	Repository() {
		noofsales = 100;
		invent = new Inventory[noofsales];
		cart = new Cart[noofsales];
	}

	// Parameterized constructor
	Repository(int nos, Inventory* inv, Cart* ca) {
		noofsales = nos;
		invent = inv;
		cart = ca;
	}

	// Function to display inventory sales
	void Inventorysales(Inventory& inv) {
		cout << "no of inventory sales: " << endl;
		for (int i = 0; i < inv.noOfProduct; i++) {
			cout << "Product ID: " << inv.prod[i].ID << endl;
			cout << "Product Name: " << inv.prod[i].name << endl;
			cout << "Product Quantity: " << inv.prod[i].quantity << endl;
			cout << "Product Price: " << inv.prod[i].price << endl;
		}
	}

	// Function to display cart sales
	void Cartsales(Cart& ca) {
		if (ca.cartno > 0) {
			for (int i = 0; i < ca.cartno; i++) {
				cout << "customer name " << ca.cartquantity[i].customername << endl;
				cout << "customer quantity " << ca.cartquantity[i].customerquantity << endl;
				cout << "customer price " << ca.cartquantity[i].customerprice << endl;
				cout << "customer total amount " << ca.cartquantity[i].customerquantity * ca.cartquantity[i].customerprice << endl;
			}
		}
		else
			cout << "Sorry till cart is not added" << endl;
	}

	// Function to calculate profit for a given product ID
	void profit(Inventory& inv, int id) {
		int totalProfit = 0;
		for (int i = 0; i < inv.noOfProduct; i++) {
			if (inv.prod[i].ID == id) {
				int profitPerItem = inv.prod[i].price - inv.prod[i].costprice;
				totalProfit += profitPerItem * inv.prod[i].quantity;
				//cout << "Total profit for product ID " << id << ": " << totalProfit << endl;
			}
			else
				cout << "Invalid ID " << endl;
		}
	}
};

// Function to display the main menu options
void displayMenu() {
	cout << "Welcome to the Inventory Management System" << endl;
	cout << "1. Add new product" << endl;
	cout << "2. Order product" << endl;
	cout << "3. Take order" << endl;
	cout << "4. Update product price" << endl;
	cout << "5. Apply Ramadan discount" << endl;
	cout << "6. Apply promotion discount" << endl;
	cout << "7. Apply dynamic market price" << endl;
	cout << "8. Apply volume discount" << endl;
	cout << "9. Apply shopping discount" << endl;
	cout << "10. View inventory products" << endl;
	cout << "11. Add to cart" << endl;
	cout << "12. View cart product" << endl;
	cout << "13. Profit" << endl;
	cout << "14. Diplay Order" << endl;
	cout << "15. Remove cart" << endl;
	cout << "16. cart Discount" << endl;
	cout << "17. Refunding" << endl;
	cout << "18. Exit" << endl;
}



// Declare main function
int main() {
	// Create instances of Inventory and Cart classes
	Inventory inventory;
   Cart cart;	
	
	// Create instance of Repository class
	Repository repos;

	// Declare variable to hold user's choice
	int choice = 0;

	// Loop until user chooses to exit
	while (choice != 18) {
		// Display main menu
		displayMenu();
		cout << "Enter your choice: ";
		cin >> choice;

		// Switch statement to execute user's choice

		switch (choice) {
		case 1: {
			// Add new product
			string name;
			int quantity, price, id, costprice;
			cout << "Enter product name: ";
			cin >> name;
			cout << "Enter product quantity: ";
			cin >> quantity;
			cout << "Enter product price: ";
			cin >> price;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter product cost price: ";
			cin >> costprice;
			inventory.AddOrder(name, quantity, price, id, costprice);
			cout << "Product added successfully." << endl;
			break;
		}
		case 2: {
			// Order product
			int id, quantity;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter product quantity: ";
			cin >> quantity;
			inventory.OrderProduct(id, quantity);
			cout << "Product ordered successfully." << endl;
			break;
		}
		case 3: {
			// Take order
			int id, quantity, price;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter product quantity: ";
			cin >> quantity;
			cout << "Enter product price: ";
			cin >> price;
			inventory.takeOrder(id, quantity, price);
			cout << "Order taken successfully." << endl;
			break;
		}
		case 4: {
			// Update product price
			int id, price;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter product price: ";
			cin >> price;
			inventory.updatePrice(id, price);
			cout << "Product price updated successfully." << endl;
			break;
		}
		case 5: {
			// Apply Ramadan discount
			int id;
			int discount;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter the discount amount ";
			cin >> discount;
			inventory.RamadanDiscount(id,discount);
			cout << "Ramadan discount applied successfully." << endl;
			break;
		}
		case 6: {
			// Apply promotion discount
			int id, promdiscount;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter promotion discount: ";
			cin >> promdiscount;
			bool rez;
			rez=inventory.promotionDiscount(id, promdiscount);
			if (rez)
				cout << "promotion discount successfull" << endl;
			else
				cout << "Soory promotion is not available" << endl;
			
			break;
		}
		case 7: {
			// Apply dynamic market price
			int id, marketprice;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter new market price: ";
			cin >> marketprice;
			inventory.DynamicMarketPrice(id, marketprice);
			cout << "Market discount applied successfully." << endl;
			break;
		}
		case 8: {
			// Apply volume discount
			int id, quantity, volumediscount;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter quantity: ";
			cin >> quantity;
			cout << "Enter volume discount: ";
			cin >> volumediscount;
			inventory.VolumeDiscount(id, quantity, volumediscount);
			cout << "Volumn discount applied successfully." << endl;
			break;
		}
		case 9: {
			// Apply shopping discount
			int id, shoppingdiscount;
			cout << "Enter id: ";
			cin >> id;
			cout << "Enter shopping discount: ";
			cin >> shoppingdiscount;
			inventory.shoppingDiscount(id, shoppingdiscount);
			cout << "Shopping discount applied successfully." << endl;
			break;
		}
		case 10: {
			// View Inventoryproducts
			cout << "inventory sales" << endl;
			repos.Inventorysales(inventory);
			cout << "View inventory successfully." << endl;
			break;
		}
		case 11: {
			// Add to cart
			int id, quantity;
			cout << "Enter product ID: ";
			cin >> id;
			cout << "Enter quantity: ";
			cin >> quantity;;
			cart.AddcartItem(inventory , id, quantity);
			break;
		}
		case 12: {
			// View cartproduct or sales
			cout << "cart sales" << endl;
			repos.Cartsales(cart);
			break;
		}
		case 13: {
			// profit
			cout << "customer got profit" << endl;
			int id;
			cout << "enter the id" << endl;
			cin >> id;
			repos.profit(inventory,id);
			cout << "Profit Applied successfully." << endl;
			break;
		}
		case 14: {
			cout << "display order" << endl;
			cout << "enter the id";
			int id;
			cin >> id;
			inventory.DisplayOrder(id);
			break;
		}
		case 15: {
			cout << "remove cart order" << endl;
			cout << "enter the id";
			int id;
			cin >> id;
			cart.RemoveCartItem(inventory,id);
			cout << "Remove cart successfully." << endl;
			break;
		}
		case 16: {
			cout << "Discounr cart " << endl;
			cout << "enter the id";
			int id;
			cin >> id;
			cout << "enter the discount" << endl;
			int dis;
			cin >> dis;
			cart.Discount(inventory,id, dis);
			cout << "Discount applied successfully." << endl;
			break;
		}
		case 17: {
			cout << "Refund cart " << endl;
			cout << "enter the id";
			int id;
			cin >> id;
			cout << "enter the refuntquantity" << endl;
			int quan;
			cin >> quan;
			cout << "enter the name";
			string n;
			cin >> n;
			cart.refund(id, n, quan);
			cout << "Refunding applied successfully." << endl;
			break;
		}
		case 18: {
			// Exit
			cout << "Goodbye!" << endl;
			exit(0);
		}
		default: {
			cout << "Invalid option selected. Please try again." << endl;
			break;
		}
		}
	}

	return 0;

}








