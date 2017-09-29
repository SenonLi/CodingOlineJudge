/** StringTest.java */

import java.util.Set;
import java.util.HashSet;
import java.util.LinkedHashSet;


public class StringTest {
	/** Question: String Reversal
	 *  Given a string, write a function that returns a string that contains the same characters in the reverse order. */
	public static String reverse(String input)  {
		StringBuilder builder = new StringBuilder();
		char[] characters = input.toCharArray();

		for (int i=characters.length - 1; i >= 0; i--)  {
			builder.append(characters[i]);
		}
		return builder.toString();
	}

	/** Question: Character Uniqueness:
	 * Given a string, write a function that checks to see if every character in the string is unique*/
	public static boolean isUnique(String str)  {
		if (str.isEmpty())  return false;

		char[] charArray = str.toCharArray();
		HashSet set = new HashSet<Character>();
		for(int i = 0; i < charArray.length; i++)    {
			if(set.contains(charArray[i]))  {
				return false;
			}else {
				set.add(charArray[i]);
			}
		}
		return true;
	}

	/** Question: Remove duplicates from String
	 *  Given a string, write a function that returns the string with all duplicate characters removed. */
	public static String removeDuplicates(String input) {
		char[] charArray = input.toCharArray();
		Set<Character> uniqueCharSet = new LinkedHashSet<Character>();

		for (int i=0; i < charArray.length; i++)    {
			uniqueCharSet.add(charArray[i]);
		}
		StringBuilder uniqueSB = new StringBuilder();
		for (Character c : uniqueCharSet)   {
			uniqueSB.append(c);
		}

		return uniqueSB.toString();
	}

	public static void main(String[] arg)   {
		String helloWorld = "Hello World!";
		System.out.println(helloWorld);
		System.out.println(reverse(helloWorld));
		System.out.println(helloWorld + (isUnique(helloWorld) ? "\tis unique" : "is not unique"));
		helloWorld = removeDuplicates(helloWorld);
		System.out.println(helloWorld + (isUnique(helloWorld) ? "\tis unique" : "is not unique"));
	}
}