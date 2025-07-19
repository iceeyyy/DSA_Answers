class Solution {
    public List<String> removeSubfolders(String[] folder) {
        Set<String> st= new HashSet<>(Arrays.asList(folder));

        for(String str:folder){
            String subFolder=str;
            while(!subFolder.isEmpty()){
                int pos=subFolder.lastIndexOf('/');
                subFolder=subFolder.substring(0,pos);
                if(st.contains(subFolder)){
                    st.remove(str);
                    break;
                }
            }
        }
        return new ArrayList<>(st);
    }
}