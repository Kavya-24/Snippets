class Solution {
public:
    int minOperations(vector<string>& logs) {

        int n = logs.size();

        stack<string> st;
        // stack is used cause we need to perform operations taking care of previous element

        for(int i = 0; i < n; i++){

            if(logs[i] == "../" && !st.empty()){
            // incase string is "../" and stack is not empty we will pop the last element out of the stack
                st.pop();
            }

            else if(logs[i] != "../" && logs[i] != "./"){
            // incase element is neither of the two strings, we will push the element, which will become the current directory we are at!!
                st.push(logs[i]);
            }
        }

        int count = 0;
        // will be storing the count of operations needed to come back to the base directory i.e. main folder

        while(!st.empty()){

            count++;
            st.pop();
        }

        return count;
    }
};