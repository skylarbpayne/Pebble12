




<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Pebble12-pebble/src/arcs.h at master · skylarbpayne/Pebble12-pebble · GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="skylarbpayne/Pebble12-pebble" name="twitter:title" /><meta content="Contribute to Pebble12-pebble development by creating an account on GitHub." name="twitter:description" /><meta content="https://1.gravatar.com/avatar/840ae2328b34e750137b1137e5903e0b?d=https%3A%2F%2Fidenticons.github.com%2F2bbc540d71e2c29aa520c432e19acdcc.png&amp;r=x&amp;s=400" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://1.gravatar.com/avatar/840ae2328b34e750137b1137e5903e0b?d=https%3A%2F%2Fidenticons.github.com%2F2bbc540d71e2c29aa520c432e19acdcc.png&amp;r=x&amp;s=400" property="og:image" /><meta content="skylarbpayne/Pebble12-pebble" property="og:title" /><meta content="https://github.com/skylarbpayne/Pebble12-pebble" property="og:url" /><meta content="Contribute to Pebble12-pebble development by creating an account on GitHub." property="og:description" />

    <meta name="hostname" content="github-fe121-cp1-prd.iad.github.net">
    <meta name="ruby" content="ruby 2.1.0p0-github-tcmalloc (87c9373a41) [x86_64-linux]">
    <link rel="assets" href="https://github.global.ssl.fastly.net/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="CE755809:3CFA:A64134E:531C0F69" name="octolytics-dimension-request_id" />
    

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="nxL/GXeFpAN0gB7qbAUsweLOV9pEJww+YfS1BkWOCtE=" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-d648f1196659f589579aa6aaddcc78c4f8e87552.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-32987ede34015d8eaa4618614894d836adf201f6.css" media="all" rel="stylesheet" type="text/css" />
    
    


      <script crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/frameworks-855d68c505f4b08a77e4d991f11cf5d8f43250e2.js" type="text/javascript"></script>
      <script async="async" crossorigin="anonymous" src="https://github.global.ssl.fastly.net/assets/github-e6bd35a239a3a0ab82cd42cd9df317778e5a1270.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="2fe0694ce2393a8db660e33f758021ee">

        <link data-pjax-transient rel='permalink' href='/skylarbpayne/Pebble12-pebble/blob/cdcba8d2ba88736ac11b46f1db412da34bb99390/src/arcs.h'>

  <meta name="description" content="Contribute to Pebble12-pebble development by creating an account on GitHub." />

  <meta content="4830598" name="octolytics-dimension-user_id" /><meta content="skylarbpayne" name="octolytics-dimension-user_login" /><meta content="17545816" name="octolytics-dimension-repository_id" /><meta content="skylarbpayne/Pebble12-pebble" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="17545816" name="octolytics-dimension-repository_network_root_id" /><meta content="skylarbpayne/Pebble12-pebble" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/skylarbpayne/Pebble12-pebble/commits/master.atom" rel="alternate" title="Recent Commits to Pebble12-pebble:master" type="application/atom+xml" />

  </head>


  <body class="logged_out  env-production macintosh vis-public page-blob tipsy-tooltips">
    <a href="#start-of-content" class="accessibility-aid js-skip-to-content">Skip to content</a>
    <div class="wrapper">
      
      
      
      


      
      <div class="header header-logged-out">
  <div class="container clearfix">

    <a class="header-logo-wordmark" href="https://github.com/">
      <span class="mega-octicon octicon-logo-github"></span>
    </a>

    <div class="header-actions">
        <a class="button primary" href="/join">Sign up</a>
      <a class="button signin" href="/login?return_to=%2Fskylarbpayne%2FPebble12-pebble%2Fblob%2Fmaster%2Fsrc%2Farcs.h">Sign in</a>
    </div>

    <div class="command-bar js-command-bar  in-repository">

      <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
        <li class="features"><a href="/features">Features</a></li>
          <li class="enterprise"><a href="https://enterprise.github.com/">Enterprise</a></li>
          <li class="blog"><a href="/blog">Blog</a></li>
      </ul>
        <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    
      data-repo="skylarbpayne/Pebble12-pebble"
      data-branch="master"
      data-sha="76404706d075725a7ae60adb4ca691ba62a3b5c6"
  >

    <input type="hidden" name="nwo" value="skylarbpayne/Pebble12-pebble" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target" role="button" aria-haspopup="true">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container" aria-hidden="true">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="help tooltipped tooltipped-s" aria-label="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
    </div>

  </div>
</div>



      <div id="start-of-content" class="accessibility-aid"></div>
          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">


  <li>
    <a href="/login?return_to=%2Fskylarbpayne%2FPebble12-pebble"
    class="minibutton with-count js-toggler-target star-button tooltipped tooltipped-n"
    aria-label="You must be signed in to star a repository" rel="nofollow">
    <span class="octicon octicon-star"></span>Star
  </a>

    <a class="social-count js-social-count" href="/skylarbpayne/Pebble12-pebble/stargazers">
      0
    </a>

  </li>

    <li>
      <a href="/login?return_to=%2Fskylarbpayne%2FPebble12-pebble"
        class="minibutton with-count js-toggler-target fork-button tooltipped tooltipped-n"
        aria-label="You must be signed in to fork a repository" rel="nofollow">
        <span class="octicon octicon-git-branch"></span>Fork
      </a>
      <a href="/skylarbpayne/Pebble12-pebble/network" class="social-count">
        0
      </a>
    </li>
</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author">
            <a href="/skylarbpayne" class="url fn" itemprop="url" rel="author"><span itemprop="title">skylarbpayne</span></a>
          </span>
          <span class="repohead-name-divider">/</span>
          <strong><a href="/skylarbpayne/Pebble12-pebble" class="js-current-repository js-repo-home-link">Pebble12-pebble</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar clearfix">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped tooltipped-w" aria-label="Code">
        <a href="/skylarbpayne/Pebble12-pebble" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-gotokey="c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /skylarbpayne/Pebble12-pebble">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped tooltipped-w" aria-label="Issues">
          <a href="/skylarbpayne/Pebble12-pebble/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="i" data-selected-links="repo_issues /skylarbpayne/Pebble12-pebble/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped tooltipped-w" aria-label="Pull Requests">
        <a href="/skylarbpayne/Pebble12-pebble/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="p" data-selected-links="repo_pulls /skylarbpayne/Pebble12-pebble/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped tooltipped-w" aria-label="Pulse">
        <a href="/skylarbpayne/Pebble12-pebble/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /skylarbpayne/Pebble12-pebble/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Graphs">
        <a href="/skylarbpayne/Pebble12-pebble/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /skylarbpayne/Pebble12-pebble/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped tooltipped-w" aria-label="Network">
        <a href="/skylarbpayne/Pebble12-pebble/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /skylarbpayne/Pebble12-pebble/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url open"
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=clone">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/skylarbpayne/Pebble12-pebble.git" readonly="readonly">

    <span aria-label="copy to clipboard" class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/skylarbpayne/Pebble12-pebble.git" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=clone">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/skylarbpayne/Pebble12-pebble" readonly="readonly">

    <span aria-label="copy to clipboard" class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/skylarbpayne/Pebble12-pebble" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="help tooltipped tooltipped-n" aria-label="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>

  <a href="http://mac.github.com" data-url="github-mac://openRepo/https://github.com/skylarbpayne/Pebble12-pebble" class="minibutton sidebar-button js-conduit-rewrite-url">
    <span class="octicon octicon-device-desktop"></span>
    Clone in Desktop
  </a>


                <a href="/skylarbpayne/Pebble12-pebble/archive/master.zip"
                   class="minibutton sidebar-button"
                   title="Download this repository as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:fb3be7550d395cdc50bf0bc29bf1132a -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/skylarbpayne/Pebble12-pebble/find/master" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    role="button" aria-label="Switch branches or tags" tabindex="0" aria-haspopup="true">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax aria-hidden="true">

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Filter branches/tags" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Filter branches/tags">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/skylarbpayne/Pebble12-pebble/blob/master/src/arcs.h"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/skylarbpayne/Pebble12-pebble" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">Pebble12-pebble</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/skylarbpayne/Pebble12-pebble/tree/master/src" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">src</span></a></span><span class="separator"> / </span><strong class="final-path">arcs.h</strong> <span aria-label="copy to clipboard" class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="src/arcs.h" data-copied-hint="copied!"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


  <div class="commit file-history-tease">
    <img alt="Skylar Payne" class="main-avatar js-avatar" data-user="4830598" height="24" src="https://1.gravatar.com/avatar/840ae2328b34e750137b1137e5903e0b?d=https%3A%2F%2Fidenticons.github.com%2F2bbc540d71e2c29aa520c432e19acdcc.png&amp;r=x&amp;s=140" width="24" />
    <span class="author"><a href="/skylarbpayne" rel="author">skylarbpayne</a></span>
    <time class="js-relative-date" data-title-format="YYYY-MM-DD HH:mm:ss" datetime="2014-03-08T22:18:48-08:00" title="2014-03-08 22:18:48">March 08, 2014</time>
    <div class="commit-title">
        <a href="/skylarbpayne/Pebble12-pebble/commit/3269d23d64698a67c6120ff2c2399f0a9e29a532" class="message" data-pjax="true" title="...">...</a>
    </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>1</strong> contributor</a></p>
      
    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="Skylar Payne" class=" js-avatar" data-user="4830598" height="24" src="https://1.gravatar.com/avatar/840ae2328b34e750137b1137e5903e0b?d=https%3A%2F%2Fidenticons.github.com%2F2bbc540d71e2c29aa520c432e19acdcc.png&amp;r=x&amp;s=140" width="24" />
            <a href="/skylarbpayne">skylarbpayne</a>
          </li>
      </ul>
    </div>
  </div>

<div class="file-box">
  <div class="file">
    <div class="meta clearfix">
      <div class="info file-name">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
        <span class="meta-divider"></span>
          <span>126 lines (105 sloc)</span>
          <span class="meta-divider"></span>
        <span>3.532 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
            <a class="minibutton tooltipped tooltipped-w js-conduit-openfile-check"
               href="http://mac.github.com"
               data-url="github-mac://openRepo/https://github.com/skylarbpayne/Pebble12-pebble?branch=master&amp;filepath=src%2Farcs.h"
               aria-label="Open this file in GitHub for Mac"
               data-failed-title="Your version of GitHub for Mac is too old to open this file. Try checking for updates.">
                <span class="octicon octicon-device-desktop"></span> Open
            </a>
              <a class="minibutton disabled tooltipped tooltipped-w" href="#"
                 aria-label="You must be signed in to make or propose changes">Edit</a>
          <a href="/skylarbpayne/Pebble12-pebble/raw/master/src/arcs.h" class="button minibutton " id="raw-url">Raw</a>
            <a href="/skylarbpayne/Pebble12-pebble/blame/master/src/arcs.h" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/skylarbpayne/Pebble12-pebble/commits/master/src/arcs.h" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->
          <a class="minibutton danger disabled empty-icon tooltipped tooltipped-w" href="#"
             aria-label="You must be signed in to make or propose changes">
          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-c js-blob-data">
        <table class="file-code file-diff tab-size-8">
          <tr class="file-code-line">
            <td class="blob-line-nums">
              <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="cp">#include &quot;pebble.h&quot;</span></div><div class='line' id='LC2'><br/></div><div class='line' id='LC3'><span class="cm">/*</span></div><div class='line' id='LC4'><span class="cm"> * Used for DrawArc (see below)</span></div><div class='line' id='LC5'><span class="cm"> */</span></div><div class='line' id='LC6'><span class="k">static</span> <span class="kt">int</span> <span class="n">angle_90</span> <span class="o">=</span> <span class="n">TRIG_MAX_ANGLE</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC7'><span class="k">static</span> <span class="kt">int</span> <span class="n">angle_180</span> <span class="o">=</span> <span class="n">TRIG_MAX_ANGLE</span> <span class="o">/</span> <span class="mi">2</span><span class="p">;</span></div><div class='line' id='LC8'><span class="k">static</span> <span class="kt">int</span> <span class="n">angle_270</span> <span class="o">=</span> <span class="mi">3</span> <span class="o">*</span> <span class="n">TRIG_MAX_ANGLE</span> <span class="o">/</span> <span class="mi">4</span><span class="p">;</span></div><div class='line' id='LC9'><br/></div><div class='line' id='LC10'><span class="cm">/*\</span></div><div class='line' id='LC11'><span class="cm">|*| DrawArc function thanks to Cameron MacFarland (http://forums.getpebble.com/profile/12561/Cameron%20MacFarland)</span></div><div class='line' id='LC12'><span class="cm">\*/</span></div><div class='line' id='LC13'><span class="k">static</span> <span class="kt">void</span> <span class="nf">graphics_draw_arc</span><span class="p">(</span><span class="n">GContext</span> <span class="o">*</span><span class="n">ctx</span><span class="p">,</span> <span class="n">GPoint</span> <span class="n">center</span><span class="p">,</span> <span class="kt">int</span> <span class="n">radius</span><span class="p">,</span> <span class="kt">int</span> <span class="n">thickness</span><span class="p">,</span> <span class="kt">int</span> <span class="n">start_angle</span><span class="p">,</span> <span class="kt">int</span> <span class="n">end_angle</span><span class="p">,</span> <span class="n">GColor</span> <span class="n">c</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC14'>	<span class="kt">int32_t</span> <span class="n">xmin</span> <span class="o">=</span> <span class="mi">65535000</span><span class="p">,</span> <span class="n">xmax</span> <span class="o">=</span> <span class="o">-</span><span class="mi">65535000</span><span class="p">,</span> <span class="n">ymin</span> <span class="o">=</span> <span class="mi">65535000</span><span class="p">,</span> <span class="n">ymax</span> <span class="o">=</span> <span class="o">-</span><span class="mi">65535000</span><span class="p">;</span></div><div class='line' id='LC15'>	<span class="kt">int32_t</span> <span class="n">cosStart</span><span class="p">,</span> <span class="n">sinStart</span><span class="p">,</span> <span class="n">cosEnd</span><span class="p">,</span> <span class="n">sinEnd</span><span class="p">;</span></div><div class='line' id='LC16'>	<span class="kt">int32_t</span> <span class="n">r</span><span class="p">,</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC17'><br/></div><div class='line' id='LC18'>	<span class="k">while</span> <span class="p">(</span><span class="n">start_angle</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="n">start_angle</span> <span class="o">+=</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">;</span></div><div class='line' id='LC19'>	<span class="k">while</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="n">end_angle</span> <span class="o">+=</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">;</span></div><div class='line' id='LC20'><br/></div><div class='line' id='LC21'>	<span class="n">start_angle</span> <span class="o">%=</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">;</span></div><div class='line' id='LC22'>	<span class="n">end_angle</span> <span class="o">%=</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">;</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'>	<span class="k">if</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span> <span class="n">end_angle</span> <span class="o">=</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">;</span></div><div class='line' id='LC25'><br/></div><div class='line' id='LC26'>	<span class="k">if</span> <span class="p">(</span><span class="n">start_angle</span> <span class="o">&gt;</span> <span class="n">end_angle</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC27'>		<span class="n">graphics_draw_arc</span><span class="p">(</span><span class="n">ctx</span><span class="p">,</span> <span class="n">center</span><span class="p">,</span> <span class="n">radius</span><span class="p">,</span> <span class="n">thickness</span><span class="p">,</span> <span class="n">start_angle</span><span class="p">,</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC28'>		<span class="n">graphics_draw_arc</span><span class="p">(</span><span class="n">ctx</span><span class="p">,</span> <span class="n">center</span><span class="p">,</span> <span class="n">radius</span><span class="p">,</span> <span class="n">thickness</span><span class="p">,</span> <span class="mi">0</span><span class="p">,</span> <span class="n">end_angle</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC29'>	<span class="p">}</span> <span class="k">else</span> <span class="p">{</span></div><div class='line' id='LC30'>		<span class="c1">// Calculate bounding box for the arc to be drawn</span></div><div class='line' id='LC31'>		<span class="n">cosStart</span> <span class="o">=</span> <span class="n">cos_lookup</span><span class="p">(</span><span class="n">start_angle</span><span class="p">);</span></div><div class='line' id='LC32'>		<span class="n">sinStart</span> <span class="o">=</span> <span class="n">sin_lookup</span><span class="p">(</span><span class="n">start_angle</span><span class="p">);</span></div><div class='line' id='LC33'>		<span class="n">cosEnd</span> <span class="o">=</span> <span class="n">cos_lookup</span><span class="p">(</span><span class="n">end_angle</span><span class="p">);</span></div><div class='line' id='LC34'>		<span class="n">sinEnd</span> <span class="o">=</span> <span class="n">sin_lookup</span><span class="p">(</span><span class="n">end_angle</span><span class="p">);</span></div><div class='line' id='LC35'><br/></div><div class='line' id='LC36'>		<span class="n">r</span> <span class="o">=</span> <span class="n">radius</span><span class="p">;</span></div><div class='line' id='LC37'>		<span class="c1">// Point 1: radius &amp; start_angle</span></div><div class='line' id='LC38'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">cosStart</span><span class="p">;</span></div><div class='line' id='LC39'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">xmin</span><span class="p">)</span> <span class="n">xmin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC40'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">xmax</span><span class="p">)</span> <span class="n">xmax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC41'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">sinStart</span><span class="p">;</span></div><div class='line' id='LC42'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">ymin</span><span class="p">)</span> <span class="n">ymin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC43'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">ymax</span><span class="p">)</span> <span class="n">ymax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC44'><br/></div><div class='line' id='LC45'>		<span class="c1">// Point 2: radius &amp; end_angle</span></div><div class='line' id='LC46'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">cosEnd</span><span class="p">;</span></div><div class='line' id='LC47'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">xmin</span><span class="p">)</span> <span class="n">xmin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC48'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">xmax</span><span class="p">)</span> <span class="n">xmax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC49'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">sinEnd</span><span class="p">;</span></div><div class='line' id='LC50'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">ymin</span><span class="p">)</span> <span class="n">ymin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC51'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">ymax</span><span class="p">)</span> <span class="n">ymax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC52'><br/></div><div class='line' id='LC53'>		<span class="n">r</span> <span class="o">=</span> <span class="n">radius</span> <span class="o">-</span> <span class="n">thickness</span><span class="p">;</span></div><div class='line' id='LC54'>		<span class="c1">// Point 3: radius-thickness &amp; start_angle</span></div><div class='line' id='LC55'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">cosStart</span><span class="p">;</span></div><div class='line' id='LC56'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">xmin</span><span class="p">)</span> <span class="n">xmin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC57'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">xmax</span><span class="p">)</span> <span class="n">xmax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC58'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">sinStart</span><span class="p">;</span></div><div class='line' id='LC59'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">ymin</span><span class="p">)</span> <span class="n">ymin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC60'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">ymax</span><span class="p">)</span> <span class="n">ymax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC61'><br/></div><div class='line' id='LC62'>		<span class="c1">// Point 4: radius-thickness &amp; end_angle</span></div><div class='line' id='LC63'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">cosEnd</span><span class="p">;</span></div><div class='line' id='LC64'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">xmin</span><span class="p">)</span> <span class="n">xmin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC65'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">xmax</span><span class="p">)</span> <span class="n">xmax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC66'>		<span class="n">t</span> <span class="o">=</span> <span class="n">r</span> <span class="o">*</span> <span class="n">sinEnd</span><span class="p">;</span></div><div class='line' id='LC67'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&lt;</span> <span class="n">ymin</span><span class="p">)</span> <span class="n">ymin</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC68'>		<span class="k">if</span> <span class="p">(</span><span class="n">t</span> <span class="o">&gt;</span> <span class="n">ymax</span><span class="p">)</span> <span class="n">ymax</span> <span class="o">=</span> <span class="n">t</span><span class="p">;</span></div><div class='line' id='LC69'><br/></div><div class='line' id='LC70'>		<span class="c1">// Normalization</span></div><div class='line' id='LC71'>		<span class="n">xmin</span> <span class="o">/=</span> <span class="n">TRIG_MAX_RATIO</span><span class="p">;</span></div><div class='line' id='LC72'>		<span class="n">xmax</span> <span class="o">/=</span> <span class="n">TRIG_MAX_RATIO</span><span class="p">;</span></div><div class='line' id='LC73'>		<span class="n">ymin</span> <span class="o">/=</span> <span class="n">TRIG_MAX_RATIO</span><span class="p">;</span></div><div class='line' id='LC74'>		<span class="n">ymax</span> <span class="o">/=</span> <span class="n">TRIG_MAX_RATIO</span><span class="p">;</span></div><div class='line' id='LC75'><br/></div><div class='line' id='LC76'>		<span class="c1">// Corrections if arc crosses X or Y axis</span></div><div class='line' id='LC77'>		<span class="k">if</span> <span class="p">((</span><span class="n">start_angle</span> <span class="o">&lt;</span> <span class="n">angle_90</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">&gt;</span> <span class="n">angle_90</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC78'>			<span class="n">ymax</span> <span class="o">=</span> <span class="n">radius</span><span class="p">;</span></div><div class='line' id='LC79'>		<span class="p">}</span></div><div class='line' id='LC80'><br/></div><div class='line' id='LC81'>		<span class="k">if</span> <span class="p">((</span><span class="n">start_angle</span> <span class="o">&lt;</span> <span class="n">angle_180</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">&gt;</span> <span class="n">angle_180</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC82'>			<span class="n">xmin</span> <span class="o">=</span> <span class="o">-</span><span class="n">radius</span><span class="p">;</span></div><div class='line' id='LC83'>		<span class="p">}</span></div><div class='line' id='LC84'><br/></div><div class='line' id='LC85'>		<span class="k">if</span> <span class="p">((</span><span class="n">start_angle</span> <span class="o">&lt;</span> <span class="n">angle_270</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">&gt;</span> <span class="n">angle_270</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC86'>			<span class="n">ymin</span> <span class="o">=</span> <span class="o">-</span><span class="n">radius</span><span class="p">;</span></div><div class='line' id='LC87'>		<span class="p">}</span></div><div class='line' id='LC88'><br/></div><div class='line' id='LC89'>		<span class="c1">// Slopes for the two sides of the arc</span></div><div class='line' id='LC90'>		<span class="kt">float</span> <span class="n">sslope</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">cosStart</span><span class="o">/</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">sinStart</span><span class="p">;</span></div><div class='line' id='LC91'>		<span class="kt">float</span> <span class="n">eslope</span> <span class="o">=</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">cosEnd</span> <span class="o">/</span> <span class="p">(</span><span class="kt">float</span><span class="p">)</span><span class="n">sinEnd</span><span class="p">;</span></div><div class='line' id='LC92'><br/></div><div class='line' id='LC93'>		<span class="k">if</span> <span class="p">(</span><span class="n">end_angle</span> <span class="o">==</span> <span class="n">TRIG_MAX_ANGLE</span><span class="p">)</span> <span class="n">eslope</span> <span class="o">=</span> <span class="o">-</span><span class="mi">1000000</span><span class="p">;</span></div><div class='line' id='LC94'><br/></div><div class='line' id='LC95'>		<span class="kt">int</span> <span class="n">ir2</span> <span class="o">=</span> <span class="p">(</span><span class="n">radius</span> <span class="o">-</span> <span class="n">thickness</span><span class="p">)</span> <span class="o">*</span> <span class="p">(</span><span class="n">radius</span> <span class="o">-</span> <span class="n">thickness</span><span class="p">);</span></div><div class='line' id='LC96'>		<span class="kt">int</span> <span class="n">or2</span> <span class="o">=</span> <span class="n">radius</span> <span class="o">*</span> <span class="n">radius</span><span class="p">;</span></div><div class='line' id='LC97'><br/></div><div class='line' id='LC98'>		<span class="n">graphics_context_set_stroke_color</span><span class="p">(</span><span class="n">ctx</span><span class="p">,</span> <span class="n">c</span><span class="p">);</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'>		<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">x</span> <span class="o">=</span> <span class="n">xmin</span><span class="p">;</span> <span class="n">x</span> <span class="o">&lt;=</span> <span class="n">xmax</span><span class="p">;</span> <span class="n">x</span><span class="o">++</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC101'>			<span class="k">for</span> <span class="p">(</span><span class="kt">int</span> <span class="n">y</span> <span class="o">=</span> <span class="n">ymin</span><span class="p">;</span> <span class="n">y</span> <span class="o">&lt;=</span> <span class="n">ymax</span><span class="p">;</span> <span class="n">y</span><span class="o">++</span><span class="p">)</span></div><div class='line' id='LC102'>			<span class="p">{</span></div><div class='line' id='LC103'>				<span class="kt">int</span> <span class="n">x2</span> <span class="o">=</span> <span class="n">x</span> <span class="o">*</span> <span class="n">x</span><span class="p">;</span></div><div class='line' id='LC104'>				<span class="kt">int</span> <span class="n">y2</span> <span class="o">=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">y</span><span class="p">;</span></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'>				<span class="k">if</span> <span class="p">(</span></div><div class='line' id='LC107'>					<span class="p">(</span><span class="n">x2</span> <span class="o">+</span> <span class="n">y2</span> <span class="o">&lt;</span> <span class="n">or2</span> <span class="o">&amp;&amp;</span> <span class="n">x2</span> <span class="o">+</span> <span class="n">y2</span> <span class="o">&gt;=</span> <span class="n">ir2</span><span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span></div><div class='line' id='LC108'>						<span class="p">(</span><span class="n">y</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">&lt;</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&lt;=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">sslope</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC109'>						<span class="p">(</span><span class="n">y</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">&gt;</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&gt;=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">sslope</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC110'>						<span class="p">(</span><span class="n">y</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">&lt;=</span> <span class="n">angle_180</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC111'>						<span class="p">(</span><span class="n">y</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">&lt;=</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC112'>						<span class="p">(</span><span class="n">y</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC113'>					<span class="p">)</span> <span class="o">&amp;&amp;</span> <span class="p">(</span></div><div class='line' id='LC114'>						<span class="p">(</span><span class="n">y</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">end_angle</span> <span class="o">&lt;</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&gt;=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">eslope</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC115'>						<span class="p">(</span><span class="n">y</span> <span class="o">&lt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">end_angle</span> <span class="o">&gt;</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&lt;=</span> <span class="n">y</span> <span class="o">*</span> <span class="n">eslope</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC116'>						<span class="p">(</span><span class="n">y</span> <span class="o">&gt;</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">end_angle</span> <span class="o">&gt;=</span> <span class="n">angle_180</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC117'>						<span class="p">(</span><span class="n">y</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">end_angle</span> <span class="o">&gt;=</span> <span class="n">angle_180</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&lt;</span> <span class="mi">0</span><span class="p">)</span> <span class="o">||</span></div><div class='line' id='LC118'>						<span class="p">(</span><span class="n">y</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">start_angle</span> <span class="o">==</span> <span class="mi">0</span> <span class="o">&amp;&amp;</span> <span class="n">x</span> <span class="o">&gt;</span> <span class="mi">0</span><span class="p">)</span></div><div class='line' id='LC119'>					<span class="p">)</span></div><div class='line' id='LC120'>				<span class="p">)</span></div><div class='line' id='LC121'>				<span class="n">graphics_draw_pixel</span><span class="p">(</span><span class="n">ctx</span><span class="p">,</span> <span class="n">GPoint</span><span class="p">(</span><span class="n">center</span><span class="p">.</span><span class="n">x</span><span class="o">+</span><span class="n">x</span><span class="p">,</span> <span class="n">center</span><span class="p">.</span><span class="n">y</span><span class="o">+</span><span class="n">y</span><span class="p">));</span></div><div class='line' id='LC122'>			<span class="p">}</span></div><div class='line' id='LC123'>		<span class="p">}</span></div><div class='line' id='LC124'>	<span class="p">}</span></div><div class='line' id='LC125'><span class="p">}</span></div></pre></div></td>
          </tr>
        </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.02644s from github-fe121-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped tooltipped-w" aria-label="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped tooltipped-w"
      aria-label="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>

  </body>
</html>

