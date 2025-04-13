package lab11.lab11_mev_spring;
import org.springframework.context.ApplicationContext;
import org.springframework.context.support.ClassPathXmlApplicationContext;


public class coffee_app {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		 ApplicationContext context = new ClassPathXmlApplicationContext("beans.xml");

	        Coffee_shop coffeeShop = (Coffee_shop) context.getBean("coffeeShop");
	        coffeeShop.serveCoffee();
	}

}


