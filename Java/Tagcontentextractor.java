import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class TagContentExtractor {

  // Main method to read input and process each line
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine()); // Number of lines of input

    // Loop through each input line
    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      List<String> contents = parseTags(line); // Extract content between tags

      // If no content is found, print "None", else print the extracted content
      if (contents.isEmpty()) {
        System.out.println("None");
      } else {
        for (String content : contents) {
          System.out.println(content);
        }
      }
    }
  }

  // Method to parse the input string for content between valid tags
  private static List<String> parseTags(String line) {
    List<String> contents = new ArrayList<>();
    Stack<String> openingTags = new Stack<>(); // Stack to keep track of opening tags
    StringBuilder content = new StringBuilder(); // StringBuilder to store content between tags

    // Iterate over the input line character by character
    for (int i = 0; i < line.length(); i++) {
      // Detecting opening tag '<'
      if (line.charAt(i) == '<') {
        // Reset content if there is any unfinished content
        if (content.length() > 0) {
          content.setLength(0);
        }

        // Find the corresponding closing '>' for the current tag
        int j = line.indexOf('>', i);
        if (j == -1) {
          break; // Break if no closing '>' is found
        }

        String tag = line.substring(i + 1, j); // Extract tag name

        // Handle closing tag
        if (tag.startsWith("/")) {
          // Check if there's a corresponding opening tag and if the tags match
          if (openingTags.isEmpty() || !openingTags.pop().equals(tag.substring(1))) {
            break; // Break if tags don't match
          }
        } else {
          openingTags.push(tag); // Push opening tag to stack
        }

        i = j; // Move to the position after the closing '>'
      } 
      // Handle text content between tags
      else if (line.charAt(i) == '>') {
        continue; // Skip '>'
      } else {
        // Append characters to content only if there is exactly one unclosed opening tag
        if (openingTags.size() == 1) {
          content.append(line.charAt(i));
        }
      }
    }

    // Add extracted content to the list if there is any valid content and no unclosed tags
    if (content.length() > 0 && openingTags.isEmpty()) {
      contents.add(content.toString());
    }

    return contents;
  }
}
