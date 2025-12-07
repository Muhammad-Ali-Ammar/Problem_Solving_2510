

int getLargestRectanglueAreaUsingStack(vector<int>& height) {
  stack<pair<int, int>> st;
  int n = height.size();
  int ans = 0;

  for (int i = 0; i < n; ++i) {
    /****** PART 1 *************/
    if (st.empty() == true || height[i] >= st.top().second) {
      st.push(make_pair(i, height[i]));
    } else {
      /****** PART 2 *************/
      int lastIdx = 0;
      while (st.empty() == false && height[i] < st.top().second) {
        lastIdx = st.top().first;
        ans = max(ans, (i - lastIdx) * st.top().second);
        st.pop();
      }
      st.push(make_pair(lastIdx, height[i]));
    }
  }
  /****** PART 3 *************/
  while (st.empty() == false) {
    ans = max(ans, (n - st.top().first) * st.top().second);
    st.pop();
  }
  return ans;
}

