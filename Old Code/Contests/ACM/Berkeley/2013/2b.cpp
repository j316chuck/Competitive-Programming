/*if(a.direction == 0){ //north
        for(int i = a.y-1; i >= 0; i--){
            if(mygraph[a.x][i].number == 0){
                mygraph[a.x][i].number = counter;
                Recurse(mygraph[a.x][i], counter+1);
                mygraph[a.x][i] = 0;
            }else if(counter == mygraph[a.x][i].number){
                Recurse(mygraph[a.x][i], counter+1);
            }
        }
        return;
    }else if(a.direction == 1){ //northeast
        int x = a.x, y = a.y;
        while(x <=N && y >=0){
            y--;
            x++;
            if(mygraph[x][y].number == 0){
                mygraph[x][y].number = counter;
                Recurse(mygraph[x][y], counter+1);
                mygraph[x][y].number = 0;
            }else if(counter == mygraph[x][y].number){
                Recurse(mygraph[x][y], counter+1);
            }
        }
        return;
    }else if{

    }*/
