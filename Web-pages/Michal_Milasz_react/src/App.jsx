import { BrowserRouter, Routes, Route } from 'react-router-dom'
// import Menu from './components/Menu';
import Home from './pages/Home'
import Firma from './pages/Firma'
import Inne from './pages/Inne'
import Kredyty from './pages/Kredyty'
import OMnie from './pages/OMnie'
import Rozwod from './pages/Rozwod'
import Spadek from './pages/Spadek'
import Umowy from './pages/Umowy'


export default function App() {
  return (
    <>
      <BrowserRouter>
        <Routes>
          <Route index element={<Home />} />
          <Route path="/home" element={<Home />} />
          <Route path="/firma" element={<Firma />} />
          <Route path="/inne" element={<Inne />} />
          <Route path="/kredyty" element={<Kredyty />} />
          <Route path="/o-mnie" element={<OMnie />} />
          <Route path="/rozwod" element={<Rozwod />} />
          <Route path="/spadek" element={<Spadek />} />
          <Route path="/umowy" element={<Umowy />} />
        </Routes>
      </BrowserRouter>
    </>
  )
}
