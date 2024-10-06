import React, { Component } from 'react';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';

import Navbar from "./components/Navbar";
import News from "./components/news/News";

export default class App extends Component {
  page = 12;
  news_api = process.env.REACT_APP_NEWS_API;
  render() {
    return (
      <div>
        <Router>
          <Navbar />
          <Routes>
            <Route exact path="/business" element={<News key="business" apiKey={this.news_api} pageSize={this.page} country="us" category="business" />} />
            <Route exact path="/entertainment" element={<News key="entertainment" apiKey={this.news_api} pageSize={this.page} country="us" category="entertainment" />} />
            <Route exact path="/general" element={<News key="general" apiKey={this.news_api} pageSize={this.page} country="us" category="general" />} />
            <Route exact path="/health" element={<News key="health" apiKey={this.news_api} pageSize={this.page} country="us" category="health" />} />
            <Route exact path="/science" element={<News key="science" apiKey={this.news_api} pageSize={this.page} country="us" category="science" />} />
            <Route exact path="/sports" element={<News key="sports" apiKey={this.news_api} pageSize={this.page} country="us" category="sports" />} />
            <Route exact path="/technology" element={<News key="technology" apiKey={this.news_api} pageSize={this.page} country="us" category="technology" />} />
            <Route exact path="/home" element={<News key="general" apiKey={this.news_api} pageSize={this.page} country="us" category="general" />} />
            <Route exact path="/" element={<News key="general" apiKey={this.news_api} pageSize={this.page} country="us" category="general" />} />
          </Routes>
        </Router>
      </div>
    );
  }
}
