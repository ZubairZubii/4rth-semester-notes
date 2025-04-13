import java.util.HashMap;


 class HashRemove {
    private HashMap<Integer, String> hashmap;

    public HashRemove() {
        this.hashmap = new HashMap<>();
    }
    

    public void addElement(int key, String value) {
    	hashmap.put(key, value);
    }
    

    public void removeElement(int keyToRemove) {
        if (hashmap.containsKey(keyToRemove)) {
            String removedValue = hashmap.remove(keyToRemove);
            System.out.println("Removed element key " + keyToRemove + " and value " + removedValue);
        } else {
            System.out.println("Key " + keyToRemove + " not found in the HashMap");
        }
    }
    

    public void displayHashMap(){
        System.out.println("HashMap: " + hashmap);
    }

}

public class Task5 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		HashRemove remove = new HashRemove();

    
		remove.addElement(1, "Ali");
		remove.addElement(2, "Zubair");
		remove.addElement(3, "Bilal");
		remove.addElement(4, "Haq");
		remove.addElement(5, "Zanoon");

      
		remove.displayHashMap();

    
		remove.removeElement(2);

        
		remove.displayHashMap();
        
        
	}

}






