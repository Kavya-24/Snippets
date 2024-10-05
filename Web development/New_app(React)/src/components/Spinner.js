import React, { Component } from 'react'
import loadder from "../assets/loader.gif"

export class Spinner extends Component {
  render() {
    return (
      <div className='text-center'>
        <img src={loadder} alt='Loading'/>
      </div>
    )
  }
}

export default Spinner
