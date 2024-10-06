import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class TagContentExtractor {
  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());

    for (int i = 0; i < n; i++) {
      String line = br.readLine();
      List<String> contents = parseTags(line);
      if (contents.isEmpty()) {
        System.out.println("None");
      } else {
        for (String content : contents) {
          System.out.println(content);
        }
      }
    }
  }

  private static List<String> parseTags(String line) {
    List<String> contents = new ArrayList<>();
    Stack<String> openingTags = new Stack<>();
    StringBuilder content = new StringBuilder();

    for (int i = 0; i < line.length(); i++) {
      if (line.charAt(i) == '<') {
        if (content.length() > 0) {
          content.setLength(0);
        }
        int j = line.indexOf('>', i);
        if (j == -1) {
          break;
        }
        String tag = line.substring(i + 1, j);
        if (tag.startsWith("/")) {
          if (openingTags.isEmpty() || !openingTags.pop().equals(tag.substring(1))) {
            break;
          }
        } else {
          openingTags.push(tag);
        }
        i = j;
      } else if (line.charAt(i) == '>') {
        continue;
      } else {
        if (openingTags.size() == 1) {
          content.append(line.charAt(i));
        }
      }
    }

    if (content.length() > 0 && openingTags.isEmpty()) {
      contents.add(content.toString());
    }

    return contents;
  }
}
