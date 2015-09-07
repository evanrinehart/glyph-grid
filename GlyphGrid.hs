module GlyphGrid where

data GlyphGrid = GlyphGrid {
  inkColor :: Int -> Int -> Int -> IO (),
  paperColor :: Int -> Int -> Int -> IO (),
  write :: Int -> Int -> [Char] -> IO (),
  clear :: Int -> Int -> IO (),
  link :: Int -> IO (),
  noLink :: IO (),
  flush :: IO ()
}

data Event =
  Boot Int Int |
  MouseOver Int Int |
  MouseLeave Int Int |
  MouseExit |
  MouseEnter |
  Click Int Int (Maybe Int) |
  Select Int Int Int |
  Wheel Double |
  KeyDown Key |
  KeyUp Key |
  Character Char |
  Resize Int Int |
  Error String |
  Close
    deriving (Eq, Ord, Show, Read)

data Key = KA | KB | KC deriving (Eq, Ord, Show, Read)
data Mode = Windowed | Fullscreen deriving (Eq, Show)
data Resizable = Resizable | NotResizable deriving (Eq, Show)

withGlyphGrid :: Int -> Int -> Mode -> Resizable -> (GlyphGrid -> IO Event -> IO ()) -> IO ()
withGlyphGrid w h mode resizeable program = do
  -- build options
  -- spawn process
  -- build blocking poll command
  -- build paint interface
  -- program paint poll
  return ()


