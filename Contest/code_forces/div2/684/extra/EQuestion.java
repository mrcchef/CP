import java.util.*;



public class EQuestion {

	public static void main(String[] args){

		LinkedList lla = new LinkedList();

		LinkedList llb = new LinkedList();

		assert lla.size() == llb.size() : "empty";

		

		lla.add("Hello");

		assert lla.size() == 1 : "size";

		

		llb.add("Hello");

		assert llb.contains("Hello") : "contains";

		assert lla.get(0).equals(llb.get(0)) : "element";

		assert lla.equals(llb) : "collection";

	}

}

