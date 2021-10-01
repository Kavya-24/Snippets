private fun runLayoutAnimation(recyclerView: RecyclerView) {
    val context = recyclerView.context
    recyclerView.layoutAnimation = AnimationUtils.loadLayoutAnimation(
        context,
        R.anim.layout_fall_down
    )
    recyclerView.adapter?.notifyDataSetChanged()
    recyclerView.scheduleLayoutAnimation()
}


//When using for rv
/**
 * recyclerView.adapter = mAdapter
 * runLayoutAnimation(recyclerView)
 * 
 * . . . 
 */