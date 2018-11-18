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

	/** Question: Word order reversal
	 * Given a string that contains words separated by spaces, write a function that reverses the order of the words.*/
	public static char[] reverseWordOrder(char[] words) {
		reverseCharacters(words, 0, words.length -1);
		int wordBeginIndex = 0;
		for(int i=0; i < words.length; i++) {
			if(words[i] == ' ') {
				reverseCharacters(words, wordBeginIndex, i - 1);
				wordBeginIndex = i + 1;
			}
		}
		if(wordBeginIndex < words.length -1)
			reverseCharacters(words, wordBeginIndex, words.length -1);
		return words;
	}
	public static void reverseCharacters(char[] words, int begin, int end)    {
		for(int i=0; i < (end - begin) / 2 ; i++)  {
			char temp = words[begin + i];
			words[begin + i] = words[end -i];
			words[end -i] = temp;
		}
	}

	/** Question: String to Integer
	 * Given an integer represented as a string, write a function to convert it to an integer. */
	public static int stringToInteger(String input) {
		int result = 0;
		int index = 0;
		boolean isNegative = false;
		if (input.charAt(0) == '-')	{
			isNegative = true;
			index++;
		}

		for(; index < input.length(); index++)  {
			result *= 10;
			result += ((int)input.charAt(index) - 48); // Character '0' == 48
		}

		if(isNegative)      result *= -1;
		return result;
	}

	/** Question: Longest common substring
	 * Given two strings, find the length of the longest substring that they have in common.
	 * Time: O(m*n)
	 * Space: O(m*n) */
	public static int longestCommonSubstring(String one, String two)    {
		int m = one.length();
		int n = two.length();

		if (m == 0 && n == 0)   return 0;

		int maxLength = 0;
		int[][] commonSub = new int [m][n];

		for (int i=0; i < m ; i++)  {
			for (int j=0; j < n ; j++)  {
				if(one.charAt(i) == two.charAt(j))  {
					if (i == 0 && j == 0)
						commonSub[i][j] = 1;
					else
						commonSub[i][j] = commonSub[i-1][j-1] + 1;

					if (commonSub[i][j] > maxLength)    maxLength = commonSub[i][j];
				}
			}
		}

		return maxLength;
	}

	public static void main(String[] arg)   {
		String helloWorld = "Hello World!";
		System.out.println(helloWorld);
		System.out.println(reverse(helloWorld));
		System.out.println(helloWorld + (isUnique(helloWorld) ? "\t is unique" : "\t is not unique"));
		String uniqueHelloWorld = removeDuplicates(helloWorld);
		System.out.println(uniqueHelloWorld + (isUnique(uniqueHelloWorld) ? "\t is unique" : "\t is not unique"));
		System.out.println(reverseWordOrder(helloWorld.toCharArray()));
		System.out.println(stringToInteger("-7758521"));
		System.out.println(helloWorld + " and " + uniqueHelloWorld + "has maxCommonSubStringLength:\t" + longestCommonSubstring(helloWorld, uniqueHelloWorld));
	}
}