/**
 *  BoilerCode for RecyclerView Adapter
 */
//Imports may vary
import android.graphics.Color
import android.view.LayoutInflater
import android.view.View
import android.view.ViewGroup
import android.widget.TextView
import androidx.cardview.widget.CardView
import androidx.recyclerview.widget.RecyclerView
import com.example.memej.R
import com.example.memej.responses.workspaces.UserWorkspaces
import java.util.*


class MyAdapter(val itemClick: OnItemClickListener) :
    RecyclerView.Adapter<MyAdapter.MyViewHolder>() {


    //Initialize an empty list of the dataclass T
    var lst: List<T> = listOf()

    class MyViewHolder(itemView: View) : RecyclerView.ViewHolder(itemView) {

       //Use other items you want the layout to inflate
        val NAME = itemView.findViewById<TextView>(R.id.example_name)
       
        //Bind a single item
        fun bindPost(_listItem: T, itemClick: OnItemClickListener) {
            with(_listItem) {

                
                NAME.text = _listItem.(//Add the paramter from list object-data-class you want to add)

                itemView.setOnClickListener {
                    itemClick.clickThisItem(_listItem)
                }


            }
        }


    }

    override fun onCreateViewHolder(parent: ViewGroup, viewType: Int): MyViewHolder {

        val view =
            LayoutInflater.from(parent.context)
                .inflate(R.layout.item_recycler_view, parent, false)
        return MyAdapter.MyViewHolder(view)

    }

    override fun getItemCount(): Int {
        return lst.size

    }

    override fun onBindViewHolder(holder: MyViewHolder, position: Int) {

        holder.bindPost(lst[position], itemClick)

    }

}


interface OnItemClickListener {
    fun clickThisItem(_listItem: T)
}
