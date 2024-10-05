import React, { Component } from 'react'
import defaultImage from "../../assets/dumy.png"


export class NewsItem extends Component {
  handleImageError = (event) => {
    event.target.onerror = null;
    event.target.src = defaultImage;
    event.target.alt = "dummy image";
  };

  render() {
    let {title,description,imageUrl,newsUrl,author,date,source } = this.props;
    return (
      <div className='my-3'>
        <div className="card">
            <span className="position-absolute top-0 translate-middle badge rounded-pill bg-danger" style={{zIndex:"1",left:"85%"}}>
              {source}
            </span>
            <img src={imageUrl} loading='lazy' onError={this.handleImageError}  className="card-img-top" alt="..."/>
            <div className="card-body">
                <h5 className="card-title">{title}...</h5>
                <p className="card-text">{description}...</p>
                <p className="card-text"><small className="text-muted">By {author} on {new Date(date).toGMTString()}</small></p>
                <a href={newsUrl} target='_blanck' className="btn btn-sm btn-primary">Read more</a>
            </div>
            </div>
      </div>
    )
  }
}

export default NewsItem
