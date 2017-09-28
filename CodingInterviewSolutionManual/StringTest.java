/** StringTest.java */

public class StringTest {
	/** Question:    Given a string,
	 * write a function that returns a string that contains the same characters in the reverse order. */
	public static String reverse(String input)  {
		StringBuilder builder = new StringBuilder();
		char[] characters = input.toCharArray();

		for (int i=characters.length - 1; i >= 0; i--)  {
			builder.append(characters[i]);
		}
		return builder.toString();
	}

	public static void main(String[] arg)   {
		String helloWorld = "Hello World!";
		System.out.println(helloWorld);
		System.out.println(reverse(helloWorld));
	}
}