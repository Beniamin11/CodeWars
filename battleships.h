#include <iostream>
#include <vector>
#include <set>

using namespace std;

void addBorders(vector< vector<int> >& field)
{
    field.resize(field.size()+2);
    for ( size_t i = 0 ; i < field.size(); i++ )
         field[i].resize(field.size());

    for(size_t i=field.size()-1; i > 0; --i)
        for(size_t j=field.size()-1; j > 0; --j)
                field[i][j] = field[i-1][j-1];

    for(size_t i=0; i<field.size(); ++i)
        for(size_t j=0; j<field.size(); ++j)
            field[0][j] = field[i][0] = field[field.size()-1][j] = field[i][field.size()-1] = 0;
}

bool validate_battlefield(vector< vector<int> > field) {

    addBorders(field);
    size_t line, column, current_size;

    bool battleship = false;
    int submarine = 0;
    int destroyer = 0;
    int cruiser = 0;

    set<pair<size_t,size_t> > open_nodes;
    set<pair<size_t,size_t> > closed_nodes;

    size_t node_line;
    size_t node_column;

    enum Direction
    {
        right = 0,
        down = 1,
        not_set
    };
    int direction = Direction::not_set;

    for(line = 1; line < field.size()-1; line++ )
    {
         for(column = 1; column < field.size()-1; column++)
         {
             if( field[line][column] )
             {
                 auto pos = closed_nodes.find(make_pair(line,column));
                 if(pos == closed_nodes.end())
                 {
                     direction = Direction::not_set;
                     current_size = 0;
                     open_nodes.insert(make_pair(line,column));

                     while(!open_nodes.empty())
                     {
                         auto front_pair = *(open_nodes.begin());

                         node_line = front_pair.first;
                         node_column = front_pair.second;

                         closed_nodes.insert(make_pair(node_line,node_column));
                         open_nodes.erase(open_nodes.begin());

                         current_size++;

                         if(     field[node_line-1][node_column-1] == 1 || field[node_line+1][node_column+1] == 1 ||
                                 field[node_line-1][node_column+1] == 1 || field[node_line+1][node_column-1] == 1 || current_size > 4)
                         {
                             return false;
                         }

                         if(direction == Direction::not_set)
                            field[node_line+1][node_column] ? direction = Direction::down : direction = Direction::right;

                         if(direction == Direction::down)
                             if(field[node_line][node_column - 1] == 1|| field[node_line][node_column + 1] == 1)
                                return false;
                             else
                                {if(field[node_line+1][column] == 1)
                                    open_nodes.insert(make_pair(node_line+1, node_column));
                             }

                         if(direction == Direction::right)
                             if(field[node_line-1][node_column] == 1 || field[node_line+1][node_column] == 1)
                                return false;
                             else
                             {if(field[node_line][node_column+1] == 1)
                                 open_nodes.insert(make_pair(node_line, node_column+1));
                             }

                     }//end while

                     if(current_size == 4)
                     {
                         if(battleship)
                         return false;
                         else
                         {
                             battleship = true;
                             if(node_column > column)
                                 column = node_column;
                         }
                     }

                     if(current_size == 3)
                     {
                         if(cruiser >= 2)
                         return false;
                         else
                         {
                             cruiser++;
                             if(node_column > column)
                                 column = node_column;
                         }
                     }

                     if(current_size == 2)
                     {
                         if(destroyer >= 3)
                         return false;
                         else
                         {
                             destroyer++;
                             if(node_column > column)
                                 column = node_column;
                         }
                     }

                     if(current_size == 1)
                     {
                         if(submarine >= 4)
                         return false;
                         else
                         {
                             submarine++;
                             if(node_column > column)
                                 column = node_column;
                         }
                     }


                 }//end if closed nodes

             }//end if field not null


        }//end for column

    }//end for line

    if( !battleship || cruiser < 2 || destroyer < 3 || submarine < 4)
        return false;

    return true;
}
