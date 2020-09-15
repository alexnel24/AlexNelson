    public void breadthFirstSearch(){
        LinkedList<Node> queue = new LinkedList<>();
        queue.add(start);
        //mark the starting point as visited [cameFrom is required so null is put in]
        start.visit(null);


        while(!queue.isEmpty()){
            //dequeue the first node
            Node current = queue.remove();

            //get all of the neighbors and put them in an array
            Node[] neighbors = new Node[4];
            neighbors[0] = nodes[current.row - 1][current.col];
            neighbors[1] = nodes[current.row + 1][current.col];
            neighbors[2] = nodes[current.row][current.col - 1];
            neighbors[3] = nodes[current.row][current.col + 1];

            //if the neighbor is not a wall and has not been visited check to see if it's the end
            //if all those checks pass - MARK IT AS VISITED, CHANGE THE cameFrom, AND ADD IT TO THE QUEUE
            //IF THE NEIGHBOR IS THE END, EXIT OUT OF THE METHOD AFTER MARKING VISITED AND CHANGING THE cameFrom
            for(Node n : neighbors) {
                if (n != null && !n.visited) {
                    n.visit(current);
                    if (n == end)
                        return;
                    queue.add(n);
                }
            }
        }
    }
